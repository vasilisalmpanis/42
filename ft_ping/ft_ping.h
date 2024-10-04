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

#define PACKET_SIZE 64 /* subject to change */

#define true 1
#define false 0

typedef struct options {
        char	short_version[15];
        char	long_version[15];
	void	(* handler)(void); /* handler function for each option */
} options;

struct packet {
	struct icmphdr icmp_header;
	char	data[PACKET_SIZE - sizeof(struct icmphdr)];
};

struct environ {
	char	*target;
	char	*hostname;
	int	ident;		/* process id to identify packets */
	long	npackets;	/* max packets to trasmit */
	long	nreceived;	/* nummber of received packets */
	long	nrepeats;	/* number of duplicates */
	long	ntransmitted;	/* sequence # for outbound packets = #sent */
	long	nchecksum;	/* replies with bad checksum */
	long	nerrors;	/* icmp errors */

	int	interval;	/* interval between packets (msec) */
	int	preload;
	int	deadline;

	struct timespec start_time, cur_time;

	struct sockaddr_in source;
	struct sockaddr_in whereto;
};

int error(char *str);

/* checksum helpers */
uint16_t icmp_checksum(void *packet, size_t length);

/* Handlers */
void help_handler(void);
void version_handler(void);

/* DNS helpers */
void dns_lookup(char *addr_host, struct sockaddr_in *addr_con, char *ip);
void reverse_dns_lookup(char *ip, char *reverse_ip);

# endif /* FT_PING */
