#include "ft_ping.h"

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

static const char success_format_string[] = "%lu bytes from %s (%s): icmp_seq=%d ttl=%d time=%.1f ms\n";
static const char success_format_string2[] = "%lu bytes from %s: icmp_seq=%d ttl=%d time=%.1f ms\n";
static const char failure_format_string[] = "From %s (%s) icmp_seq=%d %s\n";
static const char failure_format_string2[] = "From %s icmp_seq=%d %s\n";

struct environ settings;

void sigexit(int signal __attribute((__unused__)))
{

}

void sigstatus(int signal __attribute((__unused__)))
{

}

void print_statistics()
{
	printf("\n--- %s ping statistics ---\n", settings.target);
	int packet_loss = (1 - (settings.nreceived/settings.ntransmitted)) * 100;
	printf("%ld packets transmitted, ", settings.ntransmitted);
	printf("%ld received, ", settings.nreceived);
	if (settings.nchecksum)
		printf(", +%ld corrupted", settings.nchecksum);
	if (settings.nerrors)
		printf(", +%ld errors", settings.nerrors);
	printf("%d%% packet loss, ", packet_loss);
	printf("time=2000ms\n");

	if (settings.nreceived) {
		double tmdev;
		long total = settings.nreceived;
		long tmavg = settings.tsum / total;
		long long tmvar;
		if (settings.tsum < INT_MAX)
			tmvar = (settings.tsum2 - ((settings.tsum * settings.tsum) / total)) / total;
		else 
			tmvar = (settings.tsum2 / total) - (tmavg * tmavg);
		tmdev = llsqrt(tmvar);
		printf("rtt min/avg/max/mdev = %ld.%03ld/%lu.%03ld/%ld.%03ld/%ld.%03ld ms\n",
		       (long)settings.tmin / 1000, (long)settings.tmin % 1000,
		       (unsigned long)(tmavg / 1000), (long)(tmavg % 1000),
		       (long)settings.tmax / 1000, (long)settings.tmax % 1000,
		       (long)tmdev / 1000, (long)tmdev % 1000);
	}
}

double convert_to_milli()
{
	long seconds = settings.tv_now.tv_sec - settings.prev_time->tv_sec;
	long microseconds = settings.tv_now.tv_usec - settings.prev_time->tv_usec;
	double duration = (double)(seconds * 1000.0 + microseconds / 1000.0);
	if (duration > settings.max)
		settings.max = duration;
	else if (duration < settings.min)
		settings.min = duration;
	if (settings.ntransmitted == 1)
		settings.avg = duration;
	else
		settings.avg = (((settings.ntransmitted - 1) * settings.avg) + duration) / settings.ntransmitted;
	return duration;
}

int check_options()
{
	int argc = settings.argc;
	char **argv = settings.argv;
	int j;
        for (int i = 1; i < argc; i++) {
                       int arg_length = strlen(argv[i]);
		       int found = 0;
		       j = 0;
                       for (; j < 11; j++) {
                                int option_length = strlen(ping_options[j].long_version);
                                if ((arg_length == option_length &&
					!strcmp(argv[i], ping_options[j].long_version)) ||
					(arg_length == 2 &&
					 !strcmp(argv[i], ping_options[j].short_version)))
                                {
					settings.option = i;
					settings.opt_name = argv[settings.option];
					if (ping_options[j].handler)
						found = ping_options[j].handler();
					break;
                                }
                       }
		       if (j == 11 && settings.target) {
			       error("Invalid Option\n");
			       exit(1);
		       }
		       if (found)
			       i += found - 1;
		       if (!found && !settings.target) {
			       settings.target = argv[i];
			       settings.is_ip = isValidIpAddress(argv[i]);

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


void advance_ntransmitted()
{
	settings.ntransmitted++;
}

int ping(struct sockaddr_in * addr_con)
{
	struct packet packet;
	struct timeval tv_now;
	int preload = settings.preload;

	int cc;
	int i;

	while (true)
	{
		cc = sizeof(struct packet);
		memset(&packet, 0, cc);
		packet.icmp_header.type = ICMP_ECHO;
		packet.icmp_header.code = 0;
		packet.icmp_header.checksum = 0;
		packet.icmp_header.un.echo.sequence = htons(settings.ntransmitted + 1);
		packet.icmp_header.un.echo.id = settings.ident;
		if (preload)
			advance_ntransmitted();

		gettimeofday(&tv_now, NULL);
		memcpy(packet.data, &tv_now, sizeof(tv_now));

		packet.icmp_header.checksum = icmp_checksum(&packet,cc); 
		i = sendto(settings.sock.fd, &packet, sizeof(packet), 0, 
				(struct sockaddr*)addr_con, sizeof(*addr_con));
		preload--;
		if (preload <= 0)
			break;
	}
	return i == cc ? 0 : i;
}

int gather_statistics(double duration, int csfailed)
{
	++settings.nreceived;
	if (!csfailed) {
		settings.tsum += duration; 
		settings.tsum2 = (double)((long long)duration * (long long)duration);
		if ((long)duration > settings.tmax)
			settings.tmax = (long)duration;
		if ((long)duration < settings.tmin)
			settings.tmin = (long)duration;
		if (!settings.rtt)
			settings.rtt = (long)duration * 8;
		else
			settings.rtt += (long)duration - settings.rtt / 8;
	}
	if (csfailed) {
		--settings.nreceived;
		++settings.nchecksum;
		printf(" (BAD CHECKSUM!)");
	}
	return 0;
}

int parse_reply(int cc, uint8_t *packet) 
{
	struct iphdr *iph;
	struct icmphdr *icp;
	int hlen;
	int csfailed = 0;
	int reply_ttl;

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
		if (icp->un.echo.id != (uint16_t)settings.ident) {
			if (settings.verbose) {
				printf("%d %d\n", icp->un.echo.id, (uint16_t)settings.ident);
				printf("Wrong packet id\n");
				exit(1);
			}
		}
		if (temp_cksum != ntohs(cksum)) {
			csfailed = 1;
			if (settings.verbose) {
				printf(" (BAD CHECKSUM!)");
				return 1;
			}
		}
		settings.prev_time = (struct timeval *)((uint8_t *)icp + 8);
		double duration = convert_to_milli();
		gather_statistics(duration, csfailed);
		uint16_t sequence = ntohs(icp->un.echo.sequence);
		if (!settings.is_ip)
			printf(success_format_string, cc - sizeof(struct iphdr),
						settings.reverse_ip, 
						settings.ip,
						sequence,
						reply_ttl,
						duration);
		else
			printf(success_format_string2, cc - sizeof(struct iphdr),
						settings.ip,
						sequence,
						reply_ttl,
						duration);
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
				settings.nerrors++;
				iph = (struct iphdr *) (&icp[1]);	
				int temp = iph->ihl * 4;
				icp = (struct icmphdr *) ((unsigned char *)iph + temp);
				if (icp->un.echo.id != (uint16_t)settings.ident) {
					if (settings.verbose) {
						printf("Wrong packet id\n");
						exit(1);
					}
				}
				settings.prev_time = (struct timeval *)((uint8_t *)icp + 8);
				if (!settings.error_ip[0]) {
					inet_ntop(AF_INET, &(settings.whereto.sin_addr), settings.error_ip, INET_ADDRSTRLEN);
					reverse_dns_lookup(settings.error_ip, settings.error_reverse_ip);
				}
				uint16_t error_sequence = ntohs(icp->un.echo.sequence);
				if (!settings.is_ip)
					printf(failure_format_string, settings.error_reverse_ip, settings.error_ip, 
							error_sequence, "Time to live exceeded");
				else
					printf(failure_format_string2, settings.error_ip, 
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
	struct timeval tv_out;
	tv_out.tv_sec = 1;
	tv_out.tv_usec = 0;
	/*if (setsockopt(settings.sock.fd, IPPROTO_IP, IP_RECVTTL, &ttl_opt, sizeof(ttl_opt)) < 0) {*/
	/*	perror("setsockopt IP_RECVTTL failed");*/
	/*	exit(1);*/
	/*}*/
	/*if (setsockopt(settings.sock.fd, SOL_SOCKET, SO_TIMESTAMP, &ttl_opt, sizeof(ttl_opt)) < 0) {*/
	/*	perror("setsockopt SO_TIMESTAMP failed");*/
	/*	exit(1);*/
	/*}*/
	setsockopt(fd, IPPROTO_IP, IP_TTL, &settings.ttl, sizeof(settings.ttl));
	/*setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof tv_out);*/
	while (true) {
#if 0
		printf("npackets :%ld nreceived %ld nerrors %ld\n", settings.npackets, settings.nreceived, settings.nerrors);
#endif
		if (settings.npackets && settings.nerrors + settings.nreceived >= settings.npackets)
			break;
		usleep(PING_SLEEP_RATE);
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
			gettimeofday(&settings.tv_now, NULL);
			if (cc < 0) {
				error("Error receiving packet\n");
				return ;
			}
			not_ours = parse_reply(cc, receive_packet);
			(void)not_ours;
			break;
		}
	}
}
/* PING youtube.com (172.217.18.14) 56(84) bytes of data.
 * 64 bytes from fra15s28-in-f14.1e100.net (172.217.18.14): icmp_seq=1 ttl=116 time=26.0 ms
*/

void init_settings(int argc, char **argv, char *ip, char *reverse_ip)
{
	settings.target = NULL;
	settings.sock.socktype = SOCK_RAW;
	settings.ident = getpid();
	settings.ttl = 60;
	settings.argc = argc;
	settings.argv = argv;
	settings.ip = ip;
	settings.reverse_ip = reverse_ip;
	settings.is_ip = false;
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
	init_settings(argc, argv, ip, reverse_ip);
        if (check_options() == -1) {
		return 1;
	}
	dns_lookup(settings.target, &settings.source, ip);
	if (!ip[0]) {
		printf("ping: %s: Name or service not known\n", settings.target);
		return 1;
	}
	reverse_dns_lookup(ip, reverse_ip);
	ret_val = getaddrinfo(settings.target, NULL, &hints, &result);
	if (ret_val)
		printf("%s: %s", settings.target, gai_strerror(ret_val));
	settings.sock.fd = socket (AF_INET, settings.sock.socktype, IPPROTO_ICMP); 
	if (settings.sock.fd < 0) {
		error("Problem opening socket\n");
		return (1);
	}
	if (settings.verbose)
		printf(VERBOSE_STR,settings.sock.fd,
				settings.sock.socktype == SOCK_DGRAM ? "SOCK_DGRAM" : "SOCK_RAW");
	for (ai = result; ai; ai = ai->ai_next)
	{
		if (settings.verbose) {
			printf("ai->ai_family: %s, ai->ai_canonname: '%s'\n",
				  ai->ai_family == AF_INET ? "AF_INET" : "AF_INET6",
				  ai->ai_canonname ? ai->ai_canonname : "");
		}
	}
	set_signal(SIGINT, sigexit);
	set_signal(SIGALRM, sigexit);
	set_signal(SIGQUIT, sigstatus);
	printf(PING_STR, settings.target, ip, 124);
	main_loop(&settings.source, settings.sock.fd, ip, reverse_ip);
	close(settings.sock.fd);
	print_statistics();
	freeaddrinfo(result);
        return 0;
}
