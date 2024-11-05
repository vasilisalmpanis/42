#ifndef FT_TRACEROUTE
#define FT_TRACEROUTE

#include <argp.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "defines.h"
#include "libft/libft.h"
struct sock {
    int fd;
    int type;
};

struct opts {
    int max_ttl;
    int current_ttl;
    bool verbose;
    struct sock socket;
    char *intf;
};
#endif  // !FT_TRACEROUTE
