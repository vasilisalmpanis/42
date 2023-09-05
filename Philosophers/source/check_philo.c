/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:03:49 by valmpani          #+#    #+#             */
/*   Updated: 2023/09/05 12:03:49 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_is_dead(t_prog *prog)
{
	int	i;

	i = -1;
	while (++i < prog->phil_num)
	{
		if (get_time() + prog->time_to_sleep > prog->time_to_die)
		{
			printf("%zu %d died\n", get_time() - prog->start_time, prog->threads[i].id);
			pthread_mutex_lock(&prog->is_dead);
			prog->dead = 1;
			pthread_mutex_unlock(&prog->is_dead);
		}
	}
	return (0);
}

int	check_if_full(t_prog *prog)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&prog->meal_proc);
	if (prog->meals == 0)
		return (pthread_mutex_unlock(&prog->meal_proc), 0);
	while (++i < prog->phil_num)
	{
		if (prog->threads[i].meals_eatten < prog->meals)
		{
			return (pthread_mutex_unlock(&prog->meal_proc), 0);
		}
	}
	prog->all_fed = 1;
	pthread_mutex_unlock(&prog->meal_proc);
	return (1);
}

int	join_threads(t_prog *prog)
{
	int	i;

	i = -1;
	while (++i < prog->phil_num)
	{
		if (pthread_join(prog->threads[i].philo, NULL) != 0)
			return (printf("Error joining\n"), 1);
	}
	return (0);
}

void	print_message(t_philo *thread, char *message)
{
	size_t	time;

	time = (get_time() - thread->prog->start_time) / 1000;
	pthread_mutex_lock(&thread->prog->is_dead);
	pthread_mutex_lock(&thread->prog->meal_proc);
	if (!thread->prog->dead && thread->prog->all_fed == 0)
		printf("%zu %d %s\n", time, thread->id, message);
	pthread_mutex_unlock(&thread->prog->meal_proc);
	pthread_mutex_unlock(&thread->prog->is_dead);
}
