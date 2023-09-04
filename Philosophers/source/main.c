/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:54:36 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/30 11:54:36 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//void	print_messages(t_philo *philo, char *msg)
//{
//	size_t	time;
//
//	pthread_mutex_lock(&philo->prog->is_dead);
//	if (!philo->prog->dead)
//	{
//		time = get_time() - philo->prog->start_time;
//		pthread_mutex_lock(&philo->prog->is_dead);
//		printf("%zu: philoshoper number %d is %s", time, philo->id, msg);
//		pthread_mutex_unlock(&philo->prog->is_dead);
//	}
//}

void	*routine(void *prog)
{
	t_philo	*thread;

	thread = prog;
	thread->meals_eatten += 3;
	thread->last_meal += 3;
	pthread_mutex_lock(&thread->prog->is_dead);
	printf("is dead pointer: %d\n", *(thread->dead));
	if (thread->id == 4)
		(*thread->dead) = 1;
	pthread_mutex_unlock(&thread->prog->is_dead);
	printf("%d\n", thread->id);
	printf("%d\n", thread->meals_eatten);
	printf("%zu\n", thread->last_meal);
	printf("\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_prog	*prog;
	int		*num;
	int		i;

	num = parse(argv, argc);
	if (!num)
		return (printf("Parsing error please give the correct parameters.\n"), 1);
	prog = initialize_prog(num, argc);
	if (!prog)
		return (1);
	i = -1;
	while (1)
	{
		pthread_mutex_lock(&prog->is_dead);
		if (prog->dead == 1)
			break ;
		pthread_mutex_unlock(&prog->is_dead);
	}
	i = -1;
	while (++i < prog->phil_num)
	{
		if (pthread_join(prog->threads[i].philo, NULL) != 0)
			return (2);
	}
	printf("finished\n");
	return (0);
}
