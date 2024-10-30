#include "ft_traceroute.h"
#include "libft/libft.h"

static const struct argp_option options[] = {
	{"verbose", 'V', 0, 0, "Print version info and exit", 0},
	{"interface", 'i', "device", 0, "Specify a network interface to operate with", 0},
	{"max-hops", 'm', "NUM", 0, "Set the max number of hops (max TTL to be reached). Default is 30", 0},
	{0}
};

int parse_opt(int key, char *arg, struct argp_state *state)
{
    (void)arg;
    (void)state;
    switch (key) {
        default:
            return 0;
    }
}

int main(int argc, char *argv[])
{
    struct argp argp = {options, parse_opt, "", "", NULL, NULL, NULL};
    argp_parse(&argp, argc, argv, 0, 0, 0);
    ft_strlen("helloworld\n");
    return 0;
}
