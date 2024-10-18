#include "defines.h"
#include "ft_ping.h"


int help_handler()
{
	error(HELP_STR);
	return 1;
}

int version_handler()
{
	error(VERSION);
	exit(0);
	return 1;
}

int verbose_handler()
{
	settings.verbose = true;
	return 1;
}

int is_num(char *arg)
{
	for (int i = 0; arg[i]; i++) {
		if (arg[i] < '0' || arg[i] > '9')
			exit(1);
	}
	return 0;
}

int count_handler()
{
	if (settings.option == settings.argc - 1) {
		error("Invalid Option\n");
	}
	if (is_num(settings.opt_name)) {
		printf("ping: please provide a valid number for reps\n");
		exit(1);
	}
	long packet_num = strtol(settings.opt_name, NULL, 10);
	settings.npackets = packet_num;
	return 2;
}

int ttl_handler()
{
	if (settings.option == settings.argc - 1) {
		error("Invalid Option\n");
	}
	int ttl = atoi(settings.opt_name);
	settings.ttl = ttl;
	return 2;
}
