#include "defines.h"
#include "ft_ping.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

static const options ping_options[11] = {
        [0] = { .short_version = "-h", .long_version = "--help", help_handler},
        [1] = { .short_version = "-V", .long_version = "--version", version_handler},
        [2] = { .short_version = "-v", .long_version = "--verbose", verbose_handler},
        [3] = { .short_version = "-f", .long_version = "--flood", NULL},
        [4] = { .short_version = "-n", .long_version = "--no-dns", NULL},
        [5] = { .short_version = "-s", .long_version = "--size", NULL},
        [6] = { .short_version = "-t", .long_version = "--ttl", NULL},
        [7] = { .short_version = "-w", .long_version = "--deadline", NULL},
        [8] = { .short_version = "-W", .long_version = "--timeout", NULL},
        [9] = { .short_version = "-l", .long_version = "--preload", NULL},
        [10] = { .short_version = "-c", .long_version = "--count", count_handler},
};

static const char format_string[] = "%lu bytes from %s (%s): icmp_seq=%d ttl=%d time=notyet\n";

struct environ settings;

int check_options(int argc, char **argv)
{
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
					if (ping_options[j].handler)
						ping_options[j].handler(NULL);
					found = 1;
                                }
                       }
		       if (!found) {
			       if (settings.target) {
				       error("ft_ping: invalid argument '");
				       error(argv[i]);
				       error("'\n");
				       return -1;
			       }
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

void setup_packet(struct packet *ping_packet, uint8_t *sequence)
{

	bzero(ping_packet, sizeof(struct packet));
	ping_packet->icmp_header.type = ICMP_ECHO;
	ping_packet->icmp_header.code = 0;
	ping_packet->icmp_header.un.echo.sequence = ++(*sequence);
	ping_packet->icmp_header.un.echo.id = getpid();
	ping_packet->icmp_header.checksum = icmp_checksum(ping_packet, sizeof(struct packet));
	bzero(&ping_packet->data, sizeof(ping_packet->data));
}

void ping(struct sockaddr_in *addr_con, int fd, char *ip, char *reverse_ip)
{
	struct sockaddr_in	raddress;
	struct packet		ping_packet;
	struct icmphdr		*icmp_header;
	struct iphdr		*ip_header;
	socklen_t 		length = sizeof(raddress);
	uint16_t		provided_checksum, calculated_checksum;
	uint8_t 		sequence = 0;
	uint8_t 		receive_packet[PACKET_SIZE * 2];
	size_t			result, ip_header_len;
	int			ttl = 60; /* max = 255 */

	printf("PING %s (%s) %lu bytes of data\n", settings.target, ip, sizeof(struct packet));
	while (true) {
		setsockopt(fd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
		setup_packet(&ping_packet, &sequence);
		result = sendto(fd, &ping_packet, sizeof(ping_packet), 0, (struct sockaddr *)addr_con, sizeof(*addr_con));
		if (result <= 0) {
			error("Not able to send\n");
			return ;
		}
		result = recvfrom(fd, receive_packet, PACKET_SIZE * 2, 0, (struct sockaddr *) &raddress, &length);
		if (result < 0) {
			error("Not able to receive\n");
			return ;
		}
#if 0

		printf("%lu\n", result);
		for (size_t i = 0; i < result; i++)
			printf("%x ", receive_packet[i]);
		printf("\n");
#endif /* ifdef 0 */
		ip_header = (struct iphdr *)receive_packet;
		ip_header_len = ip_header->ihl * 4;

		// Pointer to the ICMP header (skip the IP header)
		icmp_header = (struct icmphdr *)(receive_packet + ip_header_len);
		provided_checksum = htons(icmp_header->checksum);
		icmp_header->checksum = 0;
		calculated_checksum = htons(icmp_checksum(icmp_header, sizeof(*icmp_header)));
		if (calculated_checksum != provided_checksum) {
			error("Wrong checksum we dont count it\n");
			return ;
		}
		printf(format_string, result - ip_header_len, reverse_ip, ip, icmp_header->un.echo.sequence, ttl);
	}
}
/* PING youtube.com (172.217.18.14) 56(84) bytes of data.
 * 64 bytes from fra15s28-in-f14.1e100.net (172.217.18.14): icmp_seq=1 ttl=116 time=26.0 ms
*/
int main(int argc, char *argv[])
{
	struct sockaddr_in addr_con;
	struct addrinfo *ai, *result;
	struct addrinfo hints = {
		.ai_family = AF_UNSPEC,
		.ai_protocol = IPPROTO_UDP,
		.ai_flags = AI_CANONNAME,
		.ai_socktype = SOCK_DGRAM
	};
	char ip[NI_MAXHOST * sizeof(char)] =  {0};
	char reverse_ip[NI_MAXHOST * sizeof(char)] =  {0};
	int ret_val;

        if (argc == 1)
                error(ERROR_STR);
	settings.target = NULL;
	settings.sock.socktype = SOCK_DGRAM;
        if (check_options(argc, argv) == -1)
		return 1;
	dns_lookup(settings.target, &addr_con, ip);
	if (!ip[0]) {
		printf("ping: %s: Name or service not known\n", settings.target);
		return 1;
	}
	reverse_dns_lookup(ip, reverse_ip);
	ret_val = getaddrinfo(settings.target, NULL, &hints, &result);
	if (ret_val)
		printf("%s: %s", settings.target, gai_strerror(ret_val));
	(void)ai;
	for (ai = result; ai; ai = ai->ai_next)
	{
		settings.sock.fd = socket (AF_INET, settings.sock.socktype, IPPROTO_ICMP); 
		if (settings.sock.fd < 0) {
			error("Problem opening socket\n");
			return (1);
		}
		if (settings.verbose)
			printf("ping: sock4.fd: %d (socktype: %s), sock6.fd: -1 (socktype: 0), hints.ai_family: AF_INET\n\n",settings.sock.fd, settings.sock.socktype == SOCK_DGRAM ? "SOCK_DGRAM" : "SOCK_RAW"); 
		if (settings.verbose) {
			printf("ai->ai_family: %s, ai->ai_canonname: '%s'\n",
				  ai->ai_family == AF_INET ? "AF_INET" : "AF_INET6",
				  ai->ai_canonname ? ai->ai_canonname : "");
			printf("ai->ai_family: %s, ai->ai_canonname: ''\n", "AF_INET");
		}
		ping (&addr_con, settings.sock.fd, ip, reverse_ip);
		close(settings.sock.fd);
	}
        return 0;
}
