#include "defines.h"
#include "ft_ping.h"


void help_handler(void *arg)
{
	arg = (char *) arg;
	error(HELP_STR);
}

void version_handler(void *arg)
{
	arg = (char *) arg;
	error(VERSION);
}

void verbose_handler(void *arg)
{
	arg = (char *) arg;
	settings.verbose = true;
}

int is_num(char *arg)
{
	for (int i = 0; arg[i]; i++) {
		if (arg[i] < '0' || arg[i] > '9')
			exit(1);
	}
	return 0;
}

void count_handler(void *arg)
{
	arg = (char *) arg;
	if (is_num(arg)) {
		printf("ping: please provide a valid number for reps\n");
		exit(1);
	}
	long packet_num = strtol(arg, NULL, 10);
	settings.npackets = packet_num;
}
