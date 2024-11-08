#ifndef FT_TRACEROUTE
#define FT_TRACEROUTE

#include <argp.h>
#include <arpa/inet.h>
#include <bits/posix1_lim.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "defines.h"
#include "libft/libft.h"
struct sock {
    int fd;
    int type;
};

struct packet {
    struct icmphdr icmp;
    uint8_t *buf;
};

struct opts {
    char *intf;
    char *host;

    int max_ttl;
    int current_ttl;

    struct sock socket;
    bool verbose;
    size_t packetlen;

    uint8_t *packet;
    int current_hop;

    long ntransmitted;
    long ident;

    struct sockaddr_in source;
    struct sockaddr_in whereto[3];
    struct timeval rtt[3];

    char hop_ip[3][45];
    char hop_reverse_ip[3][HOST_NAME_MAX];
};

unsigned short icmp_checksum(void *packet, size_t length);
void dns_lookup(char *addr_host, struct sockaddr_in *addr_con, char *ip);
void reverse_dns_lookup(char *ip, char *reverse_ip);
#endif  // !FT_TRACEROUTE
