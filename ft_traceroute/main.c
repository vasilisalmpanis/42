#include <bits/posix1_lim.h>
#include <bits/types/struct_timeval.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/time.h>

#include "defines.h"
#include "ft_traceroute.h"
#include "libft/libft.h"

int curr_index = 1;
struct opts opts;
static const struct argp_option options[] = {
    {"verbose", 'V', 0, 0, "Print version info and exit", 0},
    {"interface", 'i', "device", 0, "Specify a network interface to operate with", 0},
    {"max-hops", 'm', "NUM", 0, "Set the max number of hops (max TTL to be reached). Default is 30", 0},
    {0}};

int ft_patse_num_str(char *s)
{
    for (size_t i = 0; i < ft_strlen(s); i++) {
        if (!ft_isdigit(s[i]))
            return 1;
    }
    return 0;
}

void print_opts()
{
    printf(
        "max ttl: %d\n"
        "verbose: %d\n"
        "intf: %s\n",
        opts.max_ttl, opts.verbose, opts.intf);
}

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
                if (ft_patse_num_str(arg)) {
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
    opts.ident        = getpid();
    opts.ntransmitted = 1;
}

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

int setup_packet()
{
    struct timeval tv_now;
    struct icmphdr *icmp;

    size_t i = 0;

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

    gettimeofday(&tv_now, NULL);

    /*printf("sending time sent %ld.%06ld\n", tv_now.tv_sec, tv_now.tv_usec);*/
    ft_memcpy(opts.packet + sizeof(struct icmphdr), &tv_now, sizeof(tv_now));

    icmp->checksum = icmp_checksum(opts.packet, opts.packetlen);
    int remainder  = opts.packetlen - (sizeof(struct timeval) + sizeof(struct icmphdr));
    while (remainder) {
        int index          = opts.packetlen - remainder;
        opts.packet[index] = 1;
        remainder--;
    }
    /*ft_print_packet_hex(opts.packet, opts.packetlen);*/
    i = sendto(opts.socket.fd, opts.packet, opts.packetlen, 0, (struct sockaddr *)&opts.source, sizeof(opts.source));
    return i == opts.packetlen ? 0 : i;
}

int parse_reply(uint8_t *packet, int cc, int probe, char *ip_host, char *reverse_ip)
{
    struct iphdr *ip;
    struct icmphdr *icmp;
    struct timeval *time;
    if (cc < 0) {
        printf("* ");
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
    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    switch (icmp->type) {
        case ICMP_ECHOREPLY:
            time                 = (struct timeval *)(packet + sizeof(struct iphdr) + sizeof(struct icmphdr));
            long seconds         = tv_now.tv_sec - time->tv_sec;
            long microseconds    = tv_now.tv_usec - time->tv_usec;
            opts.duration[probe] = (double)(seconds * 1000.0 + microseconds / 1000.0);
            ft_bzero(opts.hop_ip[probe], HOST_NAME_MAX);
            ft_bzero(opts.hop_reverse_ip[probe], HOST_NAME_MAX);
            ft_strlcpy(opts.hop_ip[probe], ip_host, ft_strlen(ip_host));
            ft_strlcpy(opts.hop_reverse_ip[probe], reverse_ip, ft_strlen(reverse_ip));

            /*printf("receiving time sent %ld.%06ld\n", time->tv_sec, time->tv_usec);*/
            return 2;
        case ICMP_TIME_EXCEEDED:
            ft_bzero(opts.hop_ip[probe], HOST_NAME_MAX);
            ft_bzero(opts.hop_reverse_ip[probe], HOST_NAME_MAX);
            inet_ntop(AF_INET, &(opts.whereto[probe].sin_addr), opts.hop_ip[probe], INET_ADDRSTRLEN);
            reverse_dns_lookup(opts.hop_ip[probe], opts.hop_reverse_ip[probe]);
            break;
    }
    return 0;
}

void print_line(int probe)
{
    if (probe == 0)
        printf("%s (%s) ", opts.hop_reverse_ip[0][0] ? opts.hop_reverse_ip[0] : opts.hop_ip[0], opts.hop_ip[0]);
    printf(" %.3f ms", opts.duration[probe]);
}

int main_loop(char *ip, char *reverse_ip)
{
    uint8_t receive_buf[3][200];
    int ret_val, cc;
    socklen_t size[3];

    size[0] = sizeof(opts.whereto[0]);
    size[1] = sizeof(opts.whereto[1]);
    size[2] = sizeof(opts.whereto[2]);
    struct timeval timeout;
    /**/
    timeout.tv_sec  = 1;
    timeout.tv_usec = 0;
    while (true) {
        cc        = 0;
        int probe = 0;
        if (opts.current_ttl == opts.max_ttl)
            break;
        printf(" %d ", opts.current_ttl);
        while (probe < PROBES) {
            setsockopt(opts.socket.fd, IPPROTO_IP, IP_TTL, &opts.current_ttl, sizeof(opts.current_ttl));
            setsockopt(opts.socket.fd, SOL_SOCKET, SO_RCVTIMEO, (void *)&timeout, sizeof(timeout));
            ret_val = setup_packet();
            if (ret_val) {
                // handle;
                return 1;
            }
            cc = recvfrom(opts.socket.fd, (void *restrict)receive_buf[probe], 200, 0,
                          (struct sockaddr *)&opts.whereto[probe], &size[probe]);
            cc = parse_reply(receive_buf[probe], cc, probe, ip, reverse_ip);
            if (cc == 0 || cc == 2)
                print_line(probe);
            if (cc == 2 && probe == 2) {
                printf("\n");
                return 0;
            }
            probe++;
        }
        opts.current_ttl++;
        printf("\n");
    }
    return 0;
}

int main(int argc, char *argv[])
{
    struct argp argp = {options, parse_opt, "", "", NULL, NULL, NULL};
    char ip[HOST_NAME_MAX];
    char reverse_ip[HOST_NAME_MAX];
    /*struct sockaddr_in addr;*/
    /*uint8_t buf[1000];*/
    /*socklen_t len = sizeof(addr);*/
    set_up_opts();
    argp_parse(&argp, argc, argv, 0, 0, 0);
    /*printf("host %s packetlen %ld\n", opts.host, opts.packetlen);*/
    opts.socket.fd   = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    opts.socket.type = SOCK_RAW;
    if (opts.socket.fd == -1)
        printf("opening socket failed\n");
    if (bind_to_intf())
        goto out;
    dns_lookup(opts.host, &opts.source, ip);
    reverse_dns_lookup(ip, reverse_ip);
    printf("traceroute to %s (%s), %d hops max, %ld byte packets\n", opts.host, ip, opts.max_ttl, opts.packetlen);
    main_loop(ip, reverse_ip);
    // start sending ICMP packets with ttl starting from 1 and increasing to max. default30
    // do reverse dns resolution and display the route.
    // exit
out:
    close(opts.socket.fd);
    return 0;
}
