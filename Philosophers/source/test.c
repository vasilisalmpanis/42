#include "philosophers.h"

void	*routine(void *arg)
{
	size_t *start;

	start = arg;
	printf("start time %zu\n", get_time() - *start);
	return (NULL);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	size_t time;
	int philos = 200;
	pthread_t threads[philos];
	int i = -1;

	time = get_time();
	while (++i < philos)
	{
		pthread_create(&threads[i], NULL, routine, (void *)&time);
	}
	i = -1;
	while (++i < philos)
		pthread_join(threads[i], NULL);
	return (0);
}
