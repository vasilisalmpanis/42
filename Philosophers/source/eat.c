/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:43:29 by valmpani          #+#    #+#             */
/*   Updated: 2023/09/05 18:43:32 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int philo_died(t_philo *thread)
{
	int	result;

	pthread_mutex_lock(&thread->prog->is_dead);
	result = thread->prog->dead;
	pthread_mutex_unlock(&thread->prog->is_dead);
	return (result);
}

int	take_right_fork(t_philo *thread, char *msg)
{
	if (philo_died(thread))
		return (1);
	pthread_mutex_lock(thread->right_fork);
	print_message(thread, msg);
	return (0);
}

int	take_left_fork(t_philo *thread, char *msg)
{
	if (philo_died(thread))
		return (1);
	pthread_mutex_lock(thread->left_fork);
	print_message(thread, msg);
	return (0);
}

int	take_forks(t_philo *thread)
{
	if (thread->id % 2 == 1 && thread->meals_eatten == 0)
	{
		print_message(thread, THINKING);
		ft_usleep(thread->prog->time_to_eat / 2);
	}
	if (thread->id % 2 == 0)
	{
		if (take_right_fork(thread, FIRST))
			return (1);
		if (take_left_fork(thread, SECOND))
			return (pthread_mutex_unlock(thread->right_fork), 1);
	}
	else
	{
		if (take_left_fork(thread, FIRST))
			return (1);
		if (take_right_fork(thread, SECOND))
			return (pthread_mutex_unlock(thread->left_fork), 1);
	}
	return (0);
}