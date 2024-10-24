#include "defines.h"
#include "ft_ping.h"

int is_num(char *arg)
{
	for (int i = 0; arg[i]; i++) {
		if (arg[i] < '0' || arg[i] > '9')
			exit(1);
	}
	return 0;
}

int interval_handler()
{
	if (settings.option == settings.argc - 1) {
		error("Invalid Option\n");
		exit(1);
	}
	if (is_num(settings.argv[settings.option + 1])) {
		printf("ping: please provide a valid interval\n");
		exit(1);
	}
	int interval = atoi(settings.argv[settings.option + 1]);
	settings.interval *= interval;
	if (interval > 2147483) {
		printf("ping: bad timing interval: %d\n", settings.interval);
		exit(1);
	}
	return 2;
}

int preload_handler()
{
	if (settings.option == settings.argc - 1) {
		error("Invalid Option\n");
		exit(1);
	}
	if (is_num(settings.argv[settings.option + 1])) {
		printf("ping: please provide a valid number for reps\n");
		exit(1);
	}
	settings.preload = atoi(settings.argv[settings.option + 1]);
	if (settings.preload > 2147483) {
		printf("ping: bad timing interval: %d\n", settings.preload);
		exit(1);
	}
	return 2;
}

int dns_handler()
{
	settings.no_dns = false;
	return 1;
}

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

int count_handler()
{
	if (settings.option == settings.argc - 1) {
		error("Invalid Option\n");
	}
	if (is_num(settings.argv[settings.option + 1])) {
		printf("ping: please provide a valid number for reps\n");
		exit(1);
	}
	long packet_num = strtol(settings.argv[settings.option + 1], NULL, 10);
	settings.npackets = packet_num;
	return 2;
}

int ttl_handler()
{
	if (settings.option == settings.argc - 1) {
		error("Invalid Option\n");
		exit(1);
	}
	int ttl = atoi(settings.argv[settings.option + 1]);
	settings.ttl = ttl;
	return 2;
}
