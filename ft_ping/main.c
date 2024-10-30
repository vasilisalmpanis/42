#include "ft_ping.h"

struct argp_option opts[] = {
	{"verbose", 'v', 0, 0, "Produce verbose output", 0},
	{"version", 'V', 0, 0, "Print version and exit", 0},
	{"force-dns", 'H', 0, 0, "Force reverse dns resolution", 0},
	{"ttl", 't', "NUM", 0, "define time to live", 0},
	{"deadline", 'w', "NUM", 0, "reply wait deadline in seconds", 0},
	{"preload", 'l', "NUM", 0, "send <preload> number of packages while waiting for replies", 0},
	{"count", 'c', "NUM", 0, "stop after <count> replies", 0},
	{"interval", 'i', "NUM", 0, "seconds between sending each packet", 0},
	{0}
};

struct environ settings;

/**
 * @brief Prints the final statistics of the
 * program. Calculates mdev and prints the rount-trip
 * time
 */
void print_statistics()
{
    printf("--- %s ping statistics ---\n", settings.target);
    int packet_loss = (1 - (settings.nreceived / settings.ntransmitted)) * 100;
    printf("%ld packets transmitted", settings.ntransmitted);
    printf(", %ld received", settings.nreceived);
    if (settings.nchecksum)
        printf(", +%ld corrupted", settings.nchecksum);
#ifdef IPUTILS
    if (settings.nerrors)
        printf(", +%ld errors", settings.nerrors);
#endif
    printf(", %d%% packet loss", packet_loss);

    if (settings.nreceived) {
        double tmdev;
        long total = settings.nreceived;
        long long tmvar;
        long tavg;
        tavg = settings.tsum / total;
        if (settings.tsum < INT_MAX)
            tmvar = (settings.tsum2 - ((settings.tsum * settings.tsum) / total)) / total;
        else
            tmvar = (settings.tsum2 / total) - (tavg);
        tmdev = llsqrt(tmvar);
        printf(RTT_STR, settings.tmin / 1000, settings.tmin % 1000, (unsigned long)(tavg / 1000),
               (long)(tavg % 1000), settings.tmax / 1000, settings.tmax % 1000, (long)tmdev / 1000,
               (long)tmdev % 1000);
    }
    printf("\n");
}

/**
 * @brief Signgal Handler, We print statistics and quit
 *
 * @param signal
 */
void sigexit(int signal __attribute((__unused__)))
{
    print_statistics();
    exit(1);
}

/**
 * @brief Signgal Handler, We print statistics and quit
 *
 * @param signal
 */
void sigstatus(int signal __attribute((__unused__)))
{
    print_statistics();
    exit(1);
}

/**
 * @brief Calculates the duration of packet response
 *
 * @return duration as double
 */
double convert_to_milli()
{
    long seconds      = settings.tv_now.tv_sec - settings.prev_time->tv_sec;
    long microseconds = settings.tv_now.tv_usec - settings.prev_time->tv_usec;
    double duration   = (double)(seconds * 1000.0 + microseconds / 1000.0);
    return duration;
}

void advance_ntransmitted() { settings.ntransmitted++; }

/**
 * @brief Initializes the packet with ICMP_ECHO (no custom types)
 * and all the reset of respective fields and sends the packet
 *
 *  ICMP Packet Structure (Echo Request)
 *
 *      0  1           2                  4                  6
 *     +----+----------+------------------+------------------+
 *     | 8  |   0      |   Checksum       |   Identifier     |
 *     |Type|  Code    |   (16 bits)      |   (16 bits)      |
 *     +----+----------+------------------+------------------+
 *     |               Sequence Number                  |
 *     |               (16 bits)                        |
 *     +------------------------------------------------+
 *     |                                               |
 *     |               Data / Payload                  |
 *     |              (Variable length)                |
 *     |                                               |
 *     +------------------------------------------------+
 *
 *  Field Descriptions:
 *    - Type (8 bits): Identifies the ICMP message type (8 for Echo Request, 0 for Echo Reply)
 *    - Code (8 bits): Provides additional context for the ICMP type (usually 0 for Echo)
 *    - Checksum (16 bits): Error-detection field for packet integrity
 *    - Identifier (16 bits): Used to match requests with replies
 *    - Sequence Number (16 bits): Helps track packet order
 *    - Data / Payload: Optional data field containing the message
 *
 * @param addr_con the destination address
 * @return 0 on send success and > 0 when not all bytes were sent
 */
int ping(struct sockaddr_in *addr_con)
{
    struct packet packet;
    struct timeval tv_now;

    int cc;
    int i;

    cc = sizeof(struct packet);
    memset(&packet, 0, cc);
    packet.icmp_header.type             = ICMP_ECHO;
    packet.icmp_header.code             = 0;
    packet.icmp_header.checksum         = 0;
    packet.icmp_header.un.echo.sequence = htons(settings.ntransmitted);
    packet.icmp_header.un.echo.id       = settings.ident;

    gettimeofday(&tv_now, NULL);
    memcpy(packet.data, &tv_now, sizeof(tv_now));

    packet.icmp_header.checksum = icmp_checksum(&packet, cc);
    i = sendto(settings.sock.fd, &packet, sizeof(packet), 0, (struct sockaddr *)addr_con,
               sizeof(*addr_con));
    return i == cc ? 0 : i;
}

/**
 * @brief calculates, max and min intervals,
 * adds to interval sum and sum square (for mdev)
 *
 * @param duration duration between sending and receiving the response
 * @param csfailed if the checksum was incorrect
 * @return 0
 */
void gather_statistics(double duration, int csfailed)
{
    long triptime = 0;
    (void)duration;

    ++settings.nreceived;
    if (!csfailed) {
        tvsub(&settings.tv_now, settings.prev_time);
        triptime = settings.tv_now.tv_sec * 1000000 + settings.tv_now.tv_usec;
        if (triptime < 0)
            printf("Warning: time of day goes back (%ldus)", triptime);

        settings.tsum += triptime;
        settings.tsum2 += (double)((long long)triptime * (long long)triptime);
        if (triptime > settings.tmax)
            settings.tmax = triptime;
        if (triptime < settings.tmin)
            settings.tmin = triptime;
        if (!settings.rtt)
            settings.rtt = triptime * 8;
        else
            settings.rtt += triptime - settings.rtt / 8;
    }
    if (csfailed) {
        --settings.nreceived;
        ++settings.nchecksum;
        printf(" (BAD CHECKSUM!)");
    }
}

/**
 * @brief Parses the received packet, checks if it
 * originates from us, if the checksum is correct
 * and the sequence of the packet and gives back feedback
 *
 * @param cc bytes read from recvfrom
 * @param packet the raw packet in the form of bytes
 * @return OURS, NOT_OURS, FAULT
 */
int parse_reply(int cc, uint8_t *packet)
{
    struct iphdr *iph;
    struct icmphdr *icp;
    int hlen;
    int csfailed = 0;
    int reply_ttl;

    iph       = (struct iphdr *)packet;
    reply_ttl = 0;

    if (settings.sock.socktype == SOCK_RAW) {
        hlen = iph->ihl * 4;
        if (cc < hlen + 8 || iph->ihl < 5) {
            error("Packet is too small\n");
            return FAULT;
        }
        reply_ttl = iph->ttl;
    } else {
        error("SOCK_DGRAM not implemented\n");
        return 1;
    }

    icp                 = (struct icmphdr *)(packet + hlen);
    uint16_t cksum      = ntohs(icp->checksum);
    icp->checksum       = 0;
    uint16_t temp_cksum = icmp_checksum((uint8_t *)icp, cc - hlen);

    if (icp->type == ICMP_ECHOREPLY) {
        if (icp->un.echo.id != (uint16_t)settings.ident)
            return NOT_OURS;

        if (temp_cksum != ntohs(cksum)) {
            csfailed = 1;
            return FAULT;
        }
        settings.prev_time = (struct timeval *)((uint8_t *)icp + 8);
        double duration    = convert_to_milli();
        gather_statistics(duration, csfailed);
        uint16_t sequence = ntohs(icp->un.echo.sequence);
        if (!settings.is_ip && !settings.no_dns)
            printf(success_format_string, cc - sizeof(struct iphdr), settings.reverse_ip,
                   settings.ip, sequence, reply_ttl, duration);
        else
            printf(success_format_string2, cc - sizeof(struct iphdr), settings.ip, sequence,
                   reply_ttl, duration);
    } else {
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
                iph      = (struct iphdr *)(&icp[1]);
                int temp = iph->ihl * 4;
                icp      = (struct icmphdr *)((unsigned char *)iph + temp);
                if (icp->un.echo.id != (uint16_t)settings.ident)
                    return NOT_OURS;
                settings.prev_time = (struct timeval *)((uint8_t *)icp + 8);
                if (!settings.error_ip[0]) {
                    inet_ntop(AF_INET, &(settings.whereto.sin_addr), settings.error_ip,
                              INET_ADDRSTRLEN);
                    reverse_dns_lookup(settings.error_ip, settings.error_reverse_ip);
                }
#ifdef IPUTILS
                /* resembling inetutils ping is actually a downgrade */

                uint16_t error_sequence = ntohs(icp->un.echo.sequence);
                if (!settings.is_ip && !settings.no_dns)
                    printf(failure_format_string, settings.error_reverse_ip, settings.error_ip,
                           error_sequence, "Time to live exceeded");
                else
                    printf(failure_format_string2, settings.error_ip, error_sequence,
                           "Time to live exceeded");
#endif
                break;
            default:
                /* MUST NOT */
                break;
        }
    }
    return 0;
}

/**
 * @brief The main ping loop, that sends packets,
 * receives them and sleeps for the predefined time
 * if 1 second or whatver the user inputs with the
 * -i flag
 *
 * @param addr_con address destination
 * @param fd file descriptor of raw socket
 * @param ip address in string format
 * @param reverse_ip adress after reverse_dns
 * @return 0 on success 1 on failure
 */
int main_loop(struct sockaddr_in *addr_con, int fd)
{
    uint8_t receive_packet[200];
    socklen_t addrlen = sizeof(settings.whereto);
    int ping_ret, cc; /*ttl_opt = 1*/
    int ret_val = OURS;
    struct timeval tv_out;
    tv_out.tv_sec  = 1;
    tv_out.tv_usec = 0;
    setsockopt(fd, IPPROTO_IP, IP_TTL, &settings.ttl, sizeof(settings.ttl));
    if (settings.deadline.tv_sec)
	    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (void *)&settings.deadline, sizeof(settings.deadline));
    while (true) {
#if 0
		printf("npackets :%ld nreceived %ld nerrors %ld\n", settings.npackets, settings.nreceived, settings.nerrors);
#endif
        if (settings.npackets && settings.nerrors + settings.nreceived >= settings.npackets)
            break;
        if (ret_val == OURS) {
            ping_ret = ping(addr_con);
            if (ping_ret == 0)
                advance_ntransmitted();

            if (ping_ret > 0)
                continue;
        }
        memset(receive_packet, 0, PACKET_SIZE * 2);
        memset(&settings.whereto, 0, sizeof(struct sockaddr_in));
        cc = recvfrom(settings.sock.fd, receive_packet, PACKET_SIZE * 2, 0,
                      (struct sockaddr *)&settings.whereto, &addrlen);
        gettimeofday(&settings.tv_now, NULL);
        if (cc < 0) {
            error("Error receiving packet\n");
            return 1;
        }
        ret_val = parse_reply(cc, receive_packet);
        switch (ret_val) {
            case OURS:
                if (settings.preload > 0)
                    settings.preload--;
                if (!settings.preload)
                    usleep(settings.interval);
                break;
            case NOT_OURS:
                break;
            case FAULT:
                return 1;
            default:
                /* MUST NOT */
                break;
        }
    }
    return 0;
}
/* PING youtube.com (172.217.18.14) 56(84) bytes of data.
 * 64 bytes from fra15s28-in-f14.1e100.net (172.217.18.14): icmp_seq=1 ttl=116 time=26.0 ms
 */

void init_settings(int argc, char **argv, char *ip, char *reverse_ip)
{
    settings.target        = NULL;
    settings.sock.socktype = SOCK_RAW;
    settings.ident         = getpid() & 0xFFFF;
    settings.ttl           = 60;
    settings.argc          = argc;
    settings.argv          = argv;
    settings.ip            = ip;
    settings.reverse_ip    = reverse_ip;
    settings.no_dns        = true;
    settings.is_ip         = false;
    settings.tmax          = 0;
    settings.tmin          = LONG_MAX;
    settings.tsum          = 0;
    settings.tsum2         = 0;
    settings.interval      = 1000000;
    memset(&settings.deadline, 0, sizeof(struct timeval));
}

/**
 * @brief Main functions of the program
 * It setups up all necessary components and runs
 * the main loop
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
#ifdef IPUTILS
    struct addrinfo *ai;
#endif
    struct addrinfo *result;
    struct addrinfo hints                      = {.ai_family   = AF_UNSPEC,
                                                  .ai_protocol = IPPROTO_UDP,
                                                  .ai_flags    = AI_CANONNAME,
                                                  .ai_socktype = SOCK_RAW};
    char ip[NI_MAXHOST * sizeof(char)]         = {0};
    char reverse_ip[NI_MAXHOST * sizeof(char)] = {0};
    struct argp argp             = {opts, parse_opt, ARGS_DOC, DOC, NULL, NULL, NULL};

    /*if (argc == 1)*/
    /*    error(ERROR_STR);*/
    init_settings(argc, argv, ip, reverse_ip);
    error_t ret_val = argp_parse(&argp, argc, argv, 0, 0, 0);
    if (ret_val) {
	    printf("Try '%s --help' or '%s --usage' for more information\n", settings.argv[0], settings.argv[0]);
	    return 1;
    };
    dns_lookup(settings.target, &settings.source, ip);
    if (!ip[0]) {
        printf("ping: %s: Name or service not known\n", settings.target);
        return 1;
    }
    if (!settings.no_dns)
        reverse_dns_lookup(ip, reverse_ip);
    ret_val = getaddrinfo(settings.target, NULL, &hints, &result);
    if (ret_val)
        printf("%s: %s", settings.target, gai_strerror(ret_val));
    settings.sock.fd = socket(AF_INET, settings.sock.socktype, IPPROTO_ICMP);
    if (settings.sock.fd < 0) {
        error("Problem opening socket\n");
        return (1);
    }
#ifdef IPUTILS
    if (settings.verbose)
        printf(VERBOSE_STR, settings.sock.fd,
               settings.sock.socktype == SOCK_DGRAM ? "SOCK_DGRAM" : "SOCK_RAW");
    for (ai = result; ai; ai = ai->ai_next) {
        if (settings.verbose) {
            printf("ai->ai_family: %s, ai->ai_canonname: '%s'\n",
                   ai->ai_family == AF_INET ? "AF_INET" : "AF_INET6",
                   ai->ai_canonname ? ai->ai_canonname : "");
        }
    }
#endif
    set_signal(SIGINT, sigexit);
    set_signal(SIGALRM, sigexit);
    set_signal(SIGQUIT, sigstatus);
    printf(PING_STR, settings.target, ip);
    if (settings.verbose)
        printf(", id 0x%04x = %u", settings.ident, settings.ident);
    printf("\n");
    if (main_loop(&settings.source, settings.sock.fd))
        exit(1);
    close(settings.sock.fd);
    print_statistics();
    freeaddrinfo(result);
    return 0;
}
