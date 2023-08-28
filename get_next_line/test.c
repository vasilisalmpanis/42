#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *temp;


	temp = ft_calloc(1,1);
	temp = ft_read_file(0, temp);
	while (strcmp(temp, "exit\n") != 0)
	{
		printf("%s\n", temp);
		free(temp);
		temp = get_next_line(0);
	}
	free(temp);
	return 1;
}