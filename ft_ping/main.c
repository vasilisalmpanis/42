#include "defines.h"
#include "ft_ping.h"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>

static const options ping_options[10] = {
        [0] = { .short_version = "-h", .long_version = "--help", help_handler},
        [1] = { .short_version = "-V", .long_version = "--version", version_handler},
        [2] = { .short_version = "-v", .long_version = "--verbose", NULL},
        [3] = { .short_version = "-f", .long_version = "--flood", NULL},
        [4] = { .short_version = "-n", .long_version = "--no-dns", NULL},
        [5] = { .short_version = "-s", .long_version = "--size", NULL},
        [6] = { .short_version = "-t", .long_version = "--ttl", NULL},
        [7] = { .short_version = "-w", .long_version = "--deadline", NULL},
        [8] = { .short_version = "-W", .long_version = "--timeout", NULL},
        [9] = { .short_version = "-l", .long_version = "--preload", NULL},
};

void check_options(int argc, char **argv)
{
        for (int i = 0; i < argc; i++) {
                       int arg_length = strlen(argv[i]);
                       for (int j = 0; j < 10; j++) {
                                int option_length = strlen(ping_options[j].long_version);
                                if ((arg_length == option_length &&
					!strcmp(argv[i], ping_options[j].long_version)) ||
					(arg_length == 2 &&
					 !strcmp(argv[i], ping_options[j].short_version)))
                                {
					if (ping_options[j].handler)
						ping_options[j].handler();
                                }
                       }
                       
        }
}

int main(int argc, char *argv[])
{
        if (argc == 1)
                error(ERROR_STR);
        check_options(argc, argv);
	/* setup environment */
	/* setup socket */
	/* configure packet */
	/* send icmp packet */
	/* loop till received */
	int fd = socket (AF_INET, SOCK_RAW, IPPROTO_ICMP); 
	if (fd < 0) {
		error("Problem opening socket\n");
		return (1);
	}
	/* use sendto and recvfrom*/
	close(fd);
	/* continue */
        return 0;
}
