#include <argp.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/socket.h>

#include "ft_traceroute.h"
#include "libft/libft.h"

struct opts opts;
static const struct argp_option options[] = {
    {"verbose", 'V', 0, 0, "Print version info and exit", 0},
    {"interface", 'i', "device", 0, "Specify a network interface to operate with", 0},
    {"max-hops", 'm', "NUM", 0, "Set the max number of hops (max TTL to be reached). Default is 30", 0},
    {0}};

void print_opts()
{
    printf(
        "max ttl: %d\n"
        "verbose: %d\n",
        opts.max_ttl, opts.verbose);
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
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

void set_up_opts()
{
    opts.max_ttl     = 30;
    opts.current_ttl = 1;
    opts.verbose     = false;
    opts.socket.fd   = 0;
    opts.socket.type = 0;
    opts.intf        = NULL;
}
int main(int argc, char *argv[])
{
    struct argp argp = {options, parse_opt, "", "", NULL, NULL, NULL};
    struct ifreq ifr;
    struct sockaddr_in addr;
    uint8_t buf[1000];
    socklen_t len = sizeof(addr);
    set_up_opts();
    argp_parse(&argp, argc, argv, 0, 0, 0);
    opts.socket.fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (opts.socket.fd == -1)
        printf("opening socket failed\n");
    if (opts.intf) {
        snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), "%s", opts.intf);
        if (setsockopt(opts.socket.fd, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr)) < 0) {
            printf("could not bind to interface\n");
        }
    }
    while (true) {
        int ret = recvfrom(opts.socket.fd, buf, 1000, 0, (struct sockaddr *)&addr, &len);
        ft_print_packet_hex(buf, ret);
	printf("\n");
    }
    // start sending ICMP packets with ttl starting from 1 and increasing to max. default30
    // do reverse dns resolution and display the route.
    // exit
    print_opts();
    close(opts.socket.fd);
    return 0;
}
