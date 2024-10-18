#ifndef FT_PING
# define FT_PING

# include <arpa/inet.h>
# include <ctype.h>
# include "defines.h"
# include <netdb.h>
# include <netinet/in.h> 
# include <netinet/ip_icmp.h>
# include <netdb.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

#define PACKET_SIZE	64
#define	MAXPACKET	65535
#define	MAXIPLEN	60
#define	MAXICMPLEN	76
#define	DEFDATALEN	(PACKET_SIZE - 8)	/* default data length */

#define true 1
#define false 0

typedef struct options {
        char	short_version[15];
        char	long_version[15];
	int	(* handler)(); /* handler function for each option */
} options;

typedef struct socket_st {
	int fd;
	int socktype;
} socket_st;

struct packet {
       struct icmphdr icmp_header;
       char    data[PACKET_SIZE - sizeof(struct icmphdr)];
} __attribute__((packed));

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

	size_t	ttl;

	socket_st sock;

	struct 	timeval tv_now;
	struct 	timeval *prev_time;
	
	// min
	// avg
	// max
	// mdev

	int	option;
	char	*opt_name;

	int 	argc;
	char 	**argv;

	char 	*ip;
	char 	*reverse_ip;

	struct sockaddr_in source;
	struct sockaddr_in whereto;
};

extern struct environ settings;

int error(char *str);

/* checksum helpers */
uint16_t icmp_checksum(void *packet, size_t length);

/* Handlers */
int help_handler();
int version_handler();
int verbose_handler();
int count_handler();
int ttl_handler();

/* DNS helpers */
void dns_lookup(char *addr_host, struct sockaddr_in *addr_con, char *ip);
void reverse_dns_lookup(char *ip, char *reverse_ip);

/* Utils */
void print_packet_hex(uint8_t *packet, int length);

# endif /* FT_PING */
