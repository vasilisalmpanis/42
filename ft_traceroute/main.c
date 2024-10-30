#include "ft_traceroute.h"
#include <argp.h>

static const struct argp_option options[] = {{0}};

int parse_opt(int key, char *arg, struct argp_state *state)
{
	(void)arg;
	(void)state;
	switch (key) {
		default:
			return 0;
	}
}

int main(int argc, char *argv[]) {
  struct argp argp = {options, parse_opt, "", "", NULL, NULL, NULL};
  argp_parse(&argp, argc, argv, 0, 0, 0);
  return 0;
}
