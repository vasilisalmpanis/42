#ifndef FT_PING
# define FT_PING

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "defines.h"

typedef struct options {
        char short_version[15];
        char long_version[15];
	void (* handler)(void);
} options;

int error(char *str);

/* Handlers */
void help_handler(void);
void version_handler(void);

# endif /* FT_PING */
