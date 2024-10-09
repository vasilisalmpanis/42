#ifndef FT_PING
# define FT_PING

# include <arpa/inet.h>
# include "defines.h"
# include <netdb.h>
# include <netinet/in.h> 
# include <netinet/ip_icmp.h>
# include <netdb.h>
# include <string.h>
# include <stdio.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

#define PACKET_SIZE 64 /* subject to change */

#define true 1
#define false 0

typedef struct options {
        char	short_version[15];
        char	long_version[15];
	void	(* handler)(void *arg); /* handler function for each option */
} options;

typedef struct socket_st {
	int fd;
	int socktype;
} socket_st;

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
	int	preload;	/* amount of packets to send before receiving */
	int	deadline;

	int	verbose;	/* verbose mode */

	socket_st sock;

	struct timespec start_time, cur_time;

	struct sockaddr_in source;
	struct sockaddr_in whereto;
};

extern struct environ settings;

int error(char *str);

/* checksum helpers */
uint16_t icmp_checksum(void *packet, size_t length);

/* Handlers */
void help_handler(void *arg);
void version_handler(void *arg);
void verbose_handler(void *arg);
void count_handler(void *arg);

/* DNS helpers */
void dns_lookup(char *addr_host, struct sockaddr_in *addr_con, char *ip);
void reverse_dns_lookup(char *ip, char *reverse_ip);

# endif /* FT_PING */
