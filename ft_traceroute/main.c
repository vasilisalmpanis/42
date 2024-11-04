#include <stdbool.h>
#include <stdio.h>

#include "ft_traceroute.h"
#include "libft/libft.h"

struct opts opts;
static const struct argp_option options[] = {
    {"verbose", 'V', 0, 0, "Print version info and exit", 0},
    {"interface", 'i', "device", 0, "Specify a network interface to operate with", 0},
    {"max-hops", 'm', "NUM", 0, "Set the max number of hops (max TTL to be reached). Default is 30",
     0},
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
            return 0;
        case 'V':
	    opts.verbose = true;
	    return 0;
        default:
            return ARGP_ERR_UNKNOWN;
    }
}

int main(int argc, char *argv[])
{
    struct argp argp = {options, parse_opt, "", "", NULL, NULL, NULL};
    argp_parse(&argp, argc, argv, 0, 0, 0);
    // create socket
    // bind to specific interface if provifed by the user.
    // start sending ICMP packets with ttl starting from 1 and increasing to max. default30
    // do reverse dns resolution and display the route.
    // exit
    print_opts();
    return 0;
}
