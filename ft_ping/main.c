#include "defines.h"
#include "ft_ping.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

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

static struct environ env;

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
						ping_options[j].handler();
					found = 1;
                                }
                       }
		       if (!found) {
			       if (env.target) {
				       error("ft_ping: invalid argument '");
				       error(argv[i]);
				       error("'\n");
				       return -1;
			       }
			       env.target = argv[i];
		       }
        }
	return 0;
}

int main(int argc, char *argv[])
{
	struct sockaddr_in addr_con;
	/* int addrlen = sizeof(addr_con); */
	char ip[NI_MAXHOST * sizeof(char)] =  {0};
	char reverse_ip[NI_MAXHOST * sizeof(char)] =  {0};

        if (argc == 1)
                error(ERROR_STR);
	env.target = NULL;
        if (check_options(argc, argv) == -1)
		return 1;
	dns_lookup(env.target, &addr_con, ip);
	reverse_dns_lookup(ip, reverse_ip);
	printf("ip: %s\nreverse: %s\n", ip, reverse_ip);
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
