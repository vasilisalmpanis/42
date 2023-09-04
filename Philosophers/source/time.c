/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:36:06 by valmpani          #+#    #+#             */
/*   Updated: 2023/09/01 11:36:06 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error with time\n");
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	ft_usleep(size_t millisec)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < millisec)
	{
		usleep(0);
	}
	return (0);
}

//int	main(void)
//{
//	struct timeval start;
//	struct timeval end;
//	long request;
//	long actual;
//	request = 5000000;
//	gettimeofday(&start, NULL);
//	ft_usleep(request);
//	gettimeofday(&end, NULL);
//	actual = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
//	printf("Request: %ld\n", request);
//	printf("Actual: %ld\n", actual);
//	return (1);
//}