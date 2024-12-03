#include "ft_traceroute.h"

int curr_index = 1;
struct opts opts;
static const struct argp_option options[] = {
    {"verbose", 'V', 0, 0, "Print version info and exit", 0},
    {"interface", 'i', "device", 0, "Specify a network interface to operate with", 0},
    {"max-hops", 'm', "NUM", 0, "Set the max number of hops (max TTL to be reached). Default is 30", 0},
    {0}};

/**
 * @brief Checks if give string is a positive number
 *
 * @param s string passed to function
 * @return 1 on error 0 if it is a valid positive number
 */
int ft_parse_num_str(char *s)
{
    for (size_t i = 0; i < ft_strlen(s); i++) {
        if (!ft_isdigit(s[i]))
            return 1;
    }
    return 0;
}

/**
 * @brief Prints the state of the opts object.
 */
void print_opts()
{
    printf(
        "max ttl: %d\n"
        "verbose: %d\n"
        "intf: %s\n",
        opts.max_ttl, opts.verbose, opts.intf);
}

/**
 * @brief Parses the options given by the user
 *
 * @param key the ascii representation of the argumrnt given
 * @param arg the whole argument string
 * @param state parse argument state
 * @return 0 on success, 1 on error
 */
int parse_opt(int key, char *arg, struct argp_state *state)
{
    (void)arg;
    (void)state;
    switch (key) {
        case 'm':
            opts.max_ttl = atoi(arg);
            break;
        case 'V':
            opts.verbose = true;
            break;
        case 'i':
            if (ft_strlen(arg) >= IFNAMSIZ) {
                printf("Please provide a valid interface name\n");
                return ARGP_ERR_UNKNOWN;
            }
            opts.intf = arg;
            break;

        case ARGP_KEY_ARG:
            if (opts.host) {
                if (opts.packetlen != 60) {
                    printf("Extra arg `%s' (position 3, argc %d)", arg, curr_index);
                    exit(1);
                }
                if (ft_parse_num_str(arg)) {
                    printf("Cannot handle \"packetlen\" cmdline arg `%s' on position 2 (argc %d)", arg, curr_index);
                    exit(1);
                }
                int packetlen = ft_atoi(arg);
                if (packetlen > 28)
                    opts.packetlen = packetlen;
                break;
            }
            opts.host = arg;
            break;
        case ARGP_KEY_END:
            if (!opts.host) {
                argp_usage(state);
                exit(1);
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    curr_index++;
    return 0;
}

/**
 * @brief initializes opts to default values
 */
void set_up_opts()
{
    opts.max_ttl      = 30;
    opts.current_ttl  = 1;
    opts.verbose      = false;
    opts.socket.fd    = 0;
    opts.socket.type  = 0;
    opts.intf         = NULL;
    opts.packetlen    = 60;
    opts.packet       = NULL;
    opts.ident        = (uint16_t)getpid();
    opts.ntransmitted = 1;
    opts.finishing    = false;
}

/**
 * @brief Bind to specific interface given by the user
 *
 * @return 0 on success, 1 on failure
 */
int bind_to_intf()
{
    struct ifreq ifr;
    if (opts.intf) {
        snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), "%s", opts.intf);
        if (setsockopt(opts.socket.fd, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr)) < 0) {
            printf("could not bind to interface\n");
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Sets up the next icmp packet and sends it
 *
 * @return 0 on success or the size of the sent packet
 */
int setup_packet()
{
    struct timeval tv_now;
    struct icmphdr *icmp;

    int i = 0;

    if (!opts.packet) {
        opts.packet = ft_calloc(opts.packetlen, sizeof(unsigned char));
        if (!opts.packet)
            return 1;
    }
    icmp                   = (struct icmphdr *)opts.packet;
    icmp->type             = ICMP_ECHO;
    icmp->code             = 0;
    icmp->checksum         = 0;
    icmp->un.echo.sequence = htons(opts.ntransmitted);
    icmp->un.echo.id       = opts.ident;

    int remainder = opts.packetlen - (sizeof(struct timeval) + sizeof(struct icmphdr));
    while (remainder) {
        int index          = opts.packetlen - remainder;
        opts.packet[index] = 1;
        remainder--;
    }
    /*ft_print_packet_hex(opts.packet, opts.packetlen);*/
    gettimeofday(&tv_now, NULL);
    ft_memcpy(opts.packet + sizeof(struct icmphdr), &tv_now, sizeof(tv_now));
    icmp->checksum = icmp_checksum(opts.packet, opts.packetlen);
    i = sendto(opts.socket.fd, opts.packet, opts.packetlen, 0, (struct sockaddr *)&opts.source, sizeof(opts.source));
    if (i == -1) {
        printf("connect: %s\n", strerror(errno));
        exit(1);
    }
    return i == (int)opts.packetlen ? 0 : i;
}

int parse_reply(uint8_t *packet, int cc, int *probe, struct timeval tv_now)
{
    struct iphdr *ip;
    struct sockaddr *addr;
    char *reverse_ip;
    struct icmphdr *icmp;
    struct timeval *time;
    if (cc < 0) {
        printf("* \n");
        return 1;
    }
    ip = (struct iphdr *)packet;
    if (opts.socket.type == SOCK_RAW) {
        int hlen = ip->ihl * 4;
        if (cc < hlen + 8 || ip->ihl < 5) {
            printf("Packet too small\n");
            return 1;
        }
    } else {
        printf("Not implemented\n");
        return 1;
    }
    icmp = (struct icmphdr *)(&ip[1]);
    gettimeofday(&tv_now, NULL);
    switch (icmp->type) {
        case ICMP_ECHOREPLY:
            if (icmp->un.echo.id != opts.ident)
                return 3;
            time              = (struct timeval *)(packet + sizeof(struct iphdr) + sizeof(struct icmphdr));
            long seconds      = tv_now.tv_sec - time->tv_sec;
            long microseconds = tv_now.tv_usec - time->tv_usec;
            (*probe)++;
            opts.duration[*probe - 1] = (double)(seconds * 1000.0 + microseconds / 1000.0);
            return 2;
        case ICMP_DEST_UNREACH:
            if (icmp->type == ICMP_DEST_UNREACH && *probe + 1 == 3)
                opts.finishing = true;
        case ICMP_TIME_EXCEEDED:
            icmp = (struct icmphdr *)(packet + 2 * sizeof(struct iphdr) + sizeof(struct icmphdr));
            if (icmp->un.echo.id != opts.ident)
                return 3;
            ft_bzero(opts.hop_ip[*probe], HOST_NAME_MAX);
            ft_bzero(opts.hop_reverse_ip[*probe], HOST_NAME_MAX);
            inet_ntop(AF_INET, &(opts.whereto[*probe].sin_addr.s_addr), opts.hop_ip[*probe], INET_ADDRSTRLEN);
            addr       = (struct sockaddr *)&opts.whereto[*probe];
            reverse_ip = opts.hop_reverse_ip[*probe];
            getnameinfo(addr, sizeof(*addr), reverse_ip, HOST_NAME_MAX, NULL, 0, 0);
            time         = (struct timeval *)(packet + 2 * sizeof(struct iphdr) + 2 * sizeof(struct icmphdr));
            seconds      = tv_now.tv_sec - time->tv_sec;
            microseconds = tv_now.tv_usec - time->tv_usec;
            (*probe)++;
            opts.duration[*probe - 1] = (double)(seconds * 1000.0 + microseconds / 1000.0);
            break;
        case ICMP_ECHO:
            return 3;
        default:
            printf("type %d code %d\n", icmp->type, icmp->code);
            exit(1);
    }
    return 0;
}

void print_line(int probe, int cc, bool *printed_host)
{
    /* first response print ttl */
    if (probe == 1)
        printf(" %d  ", opts.current_ttl);

    /* error print '*' */
    if (cc < 0) {
        printf("*%s", probe != 3 ? " " : "");
    } else if (!(*printed_host)) {
        /* print host */
        if (cc == 0)
            printf("%s (%s) ", opts.hop_reverse_ip[0][0] ? opts.hop_reverse_ip[0] : opts.hop_ip[0], opts.hop_ip[0]);
        else if (cc == 2)
            printf("%s (%s) ", opts.reverse_ip, opts.ip);
        printf("%.3f ms%s", opts.duration[probe - 1], probe == 3 ? "" : " ");
        *printed_host = true;
    } else
        printf("%.3f ms%s", opts.duration[probe - 1], probe == 3 ? "" : " "); /* print duration */
    if (probe == 3)
        printf("\n"); /* last response print newline */
}

int main_loop()
{
    uint8_t receive_buf[3][200];
    struct timeval tv_now;
    struct timeval timeout;
    fd_set read_fd;
    int ret_val, cc, probe, select_ret;
    socklen_t size[3];
    bool printed_host = false;

    size[0]         = sizeof(opts.whereto[0]);
    size[1]         = sizeof(opts.whereto[1]);
    size[2]         = sizeof(opts.whereto[2]);
    timeout.tv_sec  = 5;
    timeout.tv_usec = 0;
    probe           = 0;
    setsockopt(opts.socket.fd, IPPROTO_IP, IP_TTL, &opts.current_ttl, sizeof(opts.current_ttl));
    FD_ZERO(&read_fd);
    while (probe++ < PROBES) {
        ret_val = setup_packet();
        if (ret_val) {
            // handle;
            return 1;
        }
    }
    // TODO:
    // fix timing
    probe = 0;
    while (true) {
        // reset fd tracking
        FD_SET(opts.socket.fd, &read_fd);
        /*setsockopt(opts.socket.fd, SOL_SOCKET, SO_RCVTIMEO, (void *)&timeout, sizeof(timeout));*/
        select_ret = select(opts.socket.fd + 1, &read_fd, NULL, NULL, &timeout);
        if (select_ret < 0) {
            if (errno == EINTR)
                continue;
            else {
                printf("select: %s\n", strerror(errno));
                exit(1);
            }
        }
        if (select_ret == 1) {
            gettimeofday(&tv_now, NULL);
            cc = recvfrom(opts.socket.fd, (void *restrict)receive_buf[probe], 200, 0,
                          (struct sockaddr *)&opts.whereto[probe], &size[probe]);
            cc = parse_reply(receive_buf[probe], cc, &probe, tv_now);
            /*printf("normal reply %d\n", probe);*/
            if (cc == 3) {
                continue;
            }
            if (cc == 0 || cc == 2) {
                print_line(probe, cc, &printed_host);
                if (opts.finishing)
                    return 0;
            }
            if (cc == 2 && probe == 3) {
                return 0;
            }
            if (probe == 3) {
                ++opts.current_ttl;
                if (opts.current_ttl == opts.max_ttl + 1)
                    break;
                probe = 0;
                setsockopt(opts.socket.fd, IPPROTO_IP, IP_TTL, &opts.current_ttl, sizeof(opts.current_ttl));
                while (probe++ < 3) setup_packet();
                probe        = 0;
                printed_host = false;
            }
        } else {
            /*printf("timeout\n");*/
            probe++;
            print_line(probe, -1, &printed_host); /* print asterisk */
            timeout.tv_sec  = 1;
            timeout.tv_usec = 0;
            if (probe != 3)
                continue;
            opts.current_ttl++;
            if (opts.current_ttl == opts.max_ttl + 1)
                break;
            probe = 0;
            setsockopt(opts.socket.fd, IPPROTO_IP, IP_TTL, &opts.current_ttl, sizeof(opts.current_ttl));
            while (probe++ < 3) {
                ret_val = setup_packet();
            }
            probe        = 0;
            printed_host = false;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    struct addrinfo hints, *ai, *res;
    struct argp argp = {options, parse_opt, "", "", NULL, NULL, NULL};
    struct sockaddr_in *addr;
    int rv;

    res = NULL;
    set_up_opts();
    argp_parse(&argp, argc, argv, 0, 0, 0);

    ft_memset(&hints, 0, sizeof hints);
    hints.ai_family   = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_flags    = AI_CANONNAME;
    hints.ai_protocol = IPPROTO_ICMP;
    if ((rv = getaddrinfo(opts.host, 0, &hints, &res)) != 0) {
        printf("ft_traceroute: %s\n", gai_strerror(rv));
        exit(1);
    }
    /*printf("host %s packetlen %ld\n", opts.host, opts.packetlen);*/
    for (ai = res; ai != NULL; ai = res->ai_next) {
        if (ai->ai_family == AF_INET) {
            addr = (struct sockaddr_in *)ai->ai_addr;
            inet_ntop(ai->ai_family, &addr->sin_addr, opts.ip, INET_ADDRSTRLEN);
            opts.source = *addr;
            break;
        }
    }
    if (ai == NULL) {
        printf("ft_traceroute: failed to host\n");
        exit(1);
    }
    opts.socket.fd   = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    opts.socket.type = SOCK_RAW;
    if (opts.socket.fd == -1)
        printf("opening socket failed\n");
    if (bind_to_intf())
        goto out;
    getnameinfo((struct sockaddr *)addr, sizeof *addr, opts.reverse_ip, HOST_NAME_MAX, NULL, 0, 0);
    printf("traceroute to %s (%s), %d hops max, %ld byte packets\n", opts.host, opts.ip, opts.max_ttl, opts.packetlen);
    main_loop();
    // start sending ICMP packets with ttl starting from 1 and increasing to max. default30
    // do reverse dns resolution and display the route.
    // exit
out:
    if (res)
        freeaddrinfo(res);
    close(opts.socket.fd);
    return 0;
}
