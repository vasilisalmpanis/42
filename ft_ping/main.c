#include "defines.h"
#include "ft_ping.h"
#include <arpa/inet.h>
#include <bits/types/struct_timeval.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdint.h>
#include <stdio.h>

static const options ping_options[11] = {
        [0] = { .short_version = "-h", .long_version = "--help", help_handler},
        [1] = { .short_version = "-V", .long_version = "--version", version_handler},
        [2] = { .short_version = "-v", .long_version = "--verbose", verbose_handler},
        [3] = { .short_version = "-f", .long_version = "--flood", NULL},
        [4] = { .short_version = "-n", .long_version = "--no-dns", NULL},
        [5] = { .short_version = "-s", .long_version = "--size", NULL},
        [6] = { .short_version = "-t", .long_version = "--ttl", ttl_handler},
        [7] = { .short_version = "-w", .long_version = "--deadline", NULL},
        [8] = { .short_version = "-W", .long_version = "--timeout", NULL},
        [9] = { .short_version = "-l", .long_version = "--preload", NULL},
        [10] = { .short_version = "-c", .long_version = "--count", count_handler},
};

static const char success_format_string[] = "%lu bytes from %s (%s): icmp_seq=%d ttl=%d time=notyet\n";
static const char failure_format_string[] = "From %s (%s) icmp_seq=%d %s\n";

struct environ settings;

int check_options()
{
	int argc = settings.argc;
	char **argv = settings.argv;
        for (int i = 1; i < argc; i++) {
                       int arg_length = strlen(argv[i]);
		       int found = 0;
                       for (int j = 0; j < 10; j++) {
                                int option_length = strlen(ping_options[j].long_version);
                                if ((arg_length == option_length &&
					!strcmp(argv[i], ping_options[j].long_version)) ||
					(arg_length == 2 &&
					 !strcmp(argv[i], ping_options[j].short_version)))
                                {
					settings.option = i + 1;
					settings.opt_name = argv[settings.option];
					if (ping_options[j].handler)
						ping_options[j].handler();
					found = 1;
                                }
                       }
		       if (!found) {
			       if (!settings.target)
				       settings.target = argv[i];
		       }
	}
	if (!settings.target)
		return -1;
	return 0;
}

// for test
/*uint8_t icmp_packet[] = {*/
/*	0x0b, 0x00, 0xda, 0xd9, 0x00, 0x00, 0x00, 0x00,  // ICMP Header*/
/*	0x45, 0x00, 0x00, 0x44, 0x89, 0x1f, 0x00, 0x00,  // Original IP Header*/
/*	0x01, 0x11, 0x4a, 0xf2, 0x0a, 0x00, 0x00, 0xb0,*/
/*	0x8e, 0xfa, 0x4b, 0xee, 0xf8, 0xdf, 0x82, 0x9a,  // Start of Original UDP Datagram*/
/*	0x00, 0x30, 0x9e, 0x7b, 0x00, 0x00, 0x00, 0x00,*/
/*	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,*/
/*	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,*/
/*	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,*/
/*	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00*/
/*};*/


int ping(struct sockaddr_in * addr_con)
{
	struct packet packet;
	struct timeval tv_now;

	int cc;
	int i;

	cc = sizeof(struct packet);
	memset(&packet, 0, cc);
	packet.icmp_header.type = ICMP_ECHO;
	packet.icmp_header.code = 0;
	packet.icmp_header.checksum = 0;
	packet.icmp_header.un.echo.sequence = htons(settings.ntransmitted + 1);
	packet.icmp_header.un.echo.id = settings.ident;

	gettimeofday(&tv_now, NULL);
	memcpy(packet.data, &tv_now, sizeof(tv_now));
	/*print_packet_hex((uint8_t *)packet.data, sizeof(tv_now));*/

	packet.icmp_header.checksum = icmp_checksum(&packet,cc); 
	i = sendto(settings.sock.fd, &packet, sizeof(packet), 0, 
                           (struct sockaddr*)addr_con, sizeof(*addr_con));
	return i == cc ? 0 : i;
}

void advance_ntransmitted()
{
	settings.ntransmitted++;
}

int parse_reply(int cc, uint8_t *packet, char *ip, char *reverse_ip) 
{
	struct iphdr *iph;
	struct icmphdr *icp;
	/*struct packet *pkt;*/
	char error_ip[100] = {0};	
	char error_reverse_ip[100] = {0};	
	int hlen;
	/*int csfailed;*/
	int reply_ttl;
	/*int wrong_source = 0;*/

	iph = (struct iphdr *)packet;
	reply_ttl = 0;
	if (settings.sock.socktype == SOCK_RAW) {
		hlen = iph->ihl * 4;
		if (cc < hlen + 8 || iph->ihl < 5) {
			error("Packet is too small\n");
			return 1;
		}
		reply_ttl = iph->ttl;
		/*opts = packet + sizeof(struct iphdr);*/
		/*olen = hlen - sizeof(struct iphdr);*/
	}
	else {
		error("SOCK_DGRAM not implemented\n");
		return 1;
	}
	icp = (struct icmphdr *) (packet + hlen);	
#if DEBUG
	print_packet_hex((uint8_t *)icp, cc - hlen);
	printf("Debug: ICMP type = %d\n", icp->type);
	printf("Debug: ICMP code = %d\n", icp->code);
	printf("Debug: ICMP checksum = %x\n", icp->checksum);
	printf("Debug: ICMP id (raw) = %x\n", icp->un.echo.id);
	printf("Debug: ICMP id (converted) = %x\n", ntohs(icp->un.echo.id));
	printf("Debug: ICMP sequence (raw) = %x\n", icp->un.echo.sequence);
	printf("Debug: ICMP sequence (converted) = %x\n", ntohs(icp->un.echo.sequence));
#endif
	uint16_t cksum = ntohs(icp->checksum);
	icp->checksum = 0;
	uint16_t temp_cksum = icmp_checksum((uint8_t *)icp, cc - hlen);
	if (icp->type == ICMP_ECHOREPLY) {
		if (icp->un.echo.id != settings.ident) {
			if (settings.verbose) {
				printf("Wrong packet id\n");
				exit(1);
			}
		}
		if (temp_cksum != ntohs(cksum)) {
			if (settings.verbose) {
				printf("Wrong checksum\n");
				return 1;
			}
		}
		uint16_t sequence = ntohs(icp->un.echo.sequence);
		printf(success_format_string, cc - sizeof(struct iphdr), reverse_ip, ip, sequence, reply_ttl);
	}
	else {
		switch (icp->type) {
			case ICMP_ECHO:
				/* MUST NOT */
				return 1;
			case ICMP_SOURCE_QUENCH:
			case ICMP_REDIRECT:
			case ICMP_DEST_UNREACH:
			case ICMP_TIME_EXCEEDED:
			case ICMP_PARAMETERPROB:
				iph = (struct iphdr *) (&icp[1]);	
				int temp = iph->ihl * 4;
				icp = (struct icmphdr *) ((unsigned char *)iph + temp);
				if (icp->un.echo.id != settings.ident) {
					if (settings.verbose) {
						printf("Wrong packet id\n");
						exit(1);
					}
				}
				inet_ntop(AF_INET, &(settings.whereto.sin_addr), error_ip, INET_ADDRSTRLEN);
				reverse_dns_lookup(error_ip, error_reverse_ip);
				uint16_t error_sequence = ntohs(icp->un.echo.sequence);
				printf(failure_format_string, error_reverse_ip, error_ip, 
						error_sequence, "Time to live exceeded");
				break;
			default:
				/* MUST NOT */
				break;
		}
	}
	return 0;
}

void main_loop(struct sockaddr_in *addr_con, int fd, char *ip, char *reverse_ip)
{
	uint8_t		receive_packet[200];
	socklen_t	addrlen= sizeof(settings.whereto);
	int		ping_ret ,cc; /*ttl_opt = 1*/

	/*if (setsockopt(settings.sock.fd, IPPROTO_IP, IP_RECVTTL, &ttl_opt, sizeof(ttl_opt)) < 0) {*/
	/*	perror("setsockopt IP_RECVTTL failed");*/
	/*	exit(1);*/
	/*}*/
	/*if (setsockopt(settings.sock.fd, SOL_SOCKET, SO_TIMESTAMP, &ttl_opt, sizeof(ttl_opt)) < 0) {*/
	/*	perror("setsockopt SO_TIMESTAMP failed");*/
	/*	exit(1);*/
	/*}*/
	while (true) {
		setsockopt(fd, IPPROTO_IP, IP_TTL, &settings.ttl, sizeof(settings.ttl));
		ping_ret = ping(addr_con);
		if (ping_ret == 0) {
			advance_ntransmitted();
			//handle
		}
		
		if (ping_ret > 0) {
			// fatal bug
			printf("%s %sfatal bag\n", ip, reverse_ip);
			exit(1);
		}
		for (;;) {
			/*struct timeval *recv_timep = NULL;*/
			/*struct timeval recv_time;*/
			int not_ours = 0;
			memset(receive_packet, 0, PACKET_SIZE * 2);
			memset(&settings.whereto, 0, sizeof(struct sockaddr_in));
			cc = recvfrom(settings.sock.fd, receive_packet,
					PACKET_SIZE * 2, 0, (struct sockaddr *)&settings.whereto, &addrlen);
			if (cc < 0) {
				error("Error receiving packet\n");
				return ;
			}
			not_ours = parse_reply(cc, receive_packet, ip, reverse_ip);
			(void)not_ours;
			break;
		}
	}
}
/* PING youtube.com (172.217.18.14) 56(84) bytes of data.
 * 64 bytes from fra15s28-in-f14.1e100.net (172.217.18.14): icmp_seq=1 ttl=116 time=26.0 ms
*/

void init_settings(int argc, char **argv)
{
	settings.target = NULL;
	settings.sock.socktype = SOCK_RAW;
	settings.ident = getpid();
	settings.ttl = 60;
	settings.argc = argc;
	settings.argv = argv;
}

int main(int argc, char *argv[])
{
	struct addrinfo *ai, *result;
	struct addrinfo hints = {
		.ai_family = AF_UNSPEC,
		.ai_protocol = IPPROTO_UDP,
		.ai_flags = AI_CANONNAME,
		.ai_socktype = SOCK_RAW
	};
	char ip[NI_MAXHOST * sizeof(char)] =  {0};
	char reverse_ip[NI_MAXHOST * sizeof(char)] =  {0};
	int ret_val;

        if (argc == 1)
                error(ERROR_STR);
	init_settings(argc, argv);
        if (check_options() == -1)
		return 1;
	dns_lookup(settings.target, &settings.source, ip);
	if (!ip[0]) {
		printf("ping: %s: Name or service not known\n", settings.target);
		return 1;
	}
	reverse_dns_lookup(ip, reverse_ip);
	ret_val = getaddrinfo(settings.target, NULL, &hints, &result);
	if (ret_val)
		printf("%s: %s", settings.target, gai_strerror(ret_val));
	for (ai = result; ai; ai = ai->ai_next)
	{
		settings.sock.fd = socket (AF_INET, settings.sock.socktype, IPPROTO_ICMP); 
		if (settings.sock.fd < 0) {
			error("Problem opening socket\n");
			return (1);
		}
		if (settings.verbose)
			printf(VERBOSE_STR,settings.sock.fd,
					settings.sock.socktype == SOCK_DGRAM ? "SOCK_DGRAM" : "SOCK_RAW");
		if (settings.verbose) {
			printf("ai->ai_family: %s, ai->ai_canonname: '%s'\n",
				  ai->ai_family == AF_INET ? "AF_INET" : "AF_INET6",
				  ai->ai_canonname ? ai->ai_canonname : "");
			printf("ai->ai_family: %s, ai->ai_canonname: ''\n", "AF_INET");
		}
		printf(PING_STR, settings.target, ip, 124);
		main_loop(&settings.source, settings.sock.fd, ip, reverse_ip);
		close(settings.sock.fd);
	}
	freeaddrinfo(result);
        return 0;
}
