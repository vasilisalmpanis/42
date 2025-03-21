#ifndef FT_PING
#define FT_PING

#include <argp.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <limits.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "defines.h"

/* for iputils style output */
/*#define IPUTILS*/

#define DEFDATALEN (PACKET_SIZE - 8) /* default data length */
#define FAULT 2
#define MAXICMPLEN 76
#define MAXIPLEN 60
#define MAXPACKET 65535
#define NOT_OURS 1
#define OURS 0
#define PACKET_SIZE 64

#define true 1
#define false 0

typedef struct options {
    char short_version[15];
    char long_version[15];
    int (*handler)(); /* handler function for each option */
} options;

typedef struct socket_st {
    int fd;
    int socktype;
} socket_st;

struct packet {
    struct icmphdr icmp_header;
    char data[PACKET_SIZE - sizeof(struct icmphdr)];
} __attribute__((packed));

struct environ {
    char *target;
    char *hostname;

    int ident; /* process id to identify packets */

    long npackets;     /* max packets to trasmit */
    long nreceived;    /* nummber of received packets */
    long nrepeats;     /* number of duplicates */
    long ntransmitted; /* sequence # for outbound packets = #sent */
    long nchecksum;    /* replies with bad checksum */
    long nerrors;      /* icmp errors */
    long nduplicates;

    int interval; /* interval between packets (msec) */
    int preload;  /* amount of packets to send before receiving */
    struct timeval deadline;

    bool verbose; /* verbose mode */
    bool broadcast;
    bool no_dns;

    bool is_ip;

    size_t ttl;

    socket_st sock;

    struct timeval tv_now;
    struct timeval *prev_time;

    long mdev;

    int option;
    char *opt_name;

    int argc;
    char **argv;

    char error_ip[100];
    char error_reverse_ip[100];

    char *ip;
    char *reverse_ip;

    struct sockaddr_in source;
    struct sockaddr_in whereto;

    double tsum;
    double tsum2;
    long tmin;
    long tmax;
    int rtt;
};

extern struct environ settings;

int error(char *str);

/* checksum helpers */
uint16_t icmp_checksum(void *packet, size_t length);

/* Handlers */
int parse_opt(int key, char *arg, struct argp_state *state);

/* DNS helpers */
void dns_lookup(char *addr_host, struct sockaddr_in *addr_con, char *ip);
void reverse_dns_lookup(char *ip, char *reverse_ip);

/* Utils */
long llsqrt(long long a);
bool isValidIpAddress(char *ipAddress);
void print_packet_hex(uint8_t *packet, int length);

void print_ip_header(struct iphdr *iph);
void print_icmp_header(struct icmphdr *icmph);

static inline void set_signal(int signo, void (*handler)(int))
{
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = handler;
    sa.sa_flags   = SA_RESTART;
    sigaction(signo, &sa, NULL);
}

static inline void tvsub(struct timeval *out, struct timeval *in)
{
    if ((out->tv_usec -= in->tv_usec) < 0) {
        --out->tv_sec;
        out->tv_usec += 1000000;
    }
    out->tv_sec -= in->tv_sec;
}

#endif /* FT_PING */
