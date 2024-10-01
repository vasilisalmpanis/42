#ifndef FT_PING
# define FT_PING

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "defines.h"

# if defined(__linux__)
# include <netdb.h>
# include <netinet/in.h> 
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>
# include <unistd.h>
# endif

#define PACKET_SIZE 64

typedef struct options {
        char short_version[15];
        char long_version[15];
	void (* handler)(void);
} options;

struct packet {
	struct icmphdr icmp_header;
	char data[PACKET_SIZE - sizeof(struct icmphdr)];
};

struct environ {
	char *target;
};

int error(char *str);

/* Handlers */
void help_handler(void);
void version_handler(void);
void dns_lookup(char *addr_host, struct sockaddr_in *addr_con, char *ip);
void reverse_dns_lookup(char *ip, char *reverse_ip);
unsigned short icmp_checksum(void *packet, size_t length);

# endif /* FT_PING */
