/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:37:36 by valmpani          #+#    #+#             */
/*   Updated: 2023/09/05 18:37:42 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	update_meal_time(t_philo *thread)
{
	pthread_mutex_lock(&thread->prog->meal_proc);
	thread->meals_eatten += 1;
	thread->last_meal = get_time() + thread->prog->time_to_die;
	pthread_mutex_unlock(&thread->prog->meal_proc);
}

int	eat(t_philo *thread)
{
	if (take_forks(thread))
		return (1);
	print_message(thread, EATING);
	update_meal_time(thread);
	ft_usleep(thread->prog->time_to_eat);
	pthread_mutex_unlock(thread->left_fork);
	pthread_mutex_unlock(thread->right_fork);
	return (0);
}

int	all_full(t_philo *thread)
{
	int	result;

	pthread_mutex_lock(&thread->prog->meal_proc);
	result = thread->prog->all_fed;
	pthread_mutex_unlock(&thread->prog->meal_proc);
	return (result);
}

int	ft_sleep(t_philo *thread)
{
	if (philo_died(thread) || all_full(thread))
		return (1);
	print_message(thread, SLEEPING);
	ft_usleep(thread->prog->time_to_sleep);
	return (0);
}

int	think(t_philo *thread)
{
	if (philo_died(thread) || all_full(thread))
		return (1);
	print_message(thread, THINKING);
	return (0);
}

void	*routine(void *prog)
{
	t_philo	*thread;

	thread = prog;
	pthread_mutex_lock(&thread->prog->meal_proc);
	thread->last_meal = get_time() + thread->prog->time_to_die;
	pthread_mutex_unlock(&thread->prog->meal_proc);
	while (1)
	{
		if (eat(thread))
			break ;
//		if (philo_died(thread) || all_full(thread))
//			break ;
		if (ft_sleep(thread))
			break ;
//		if (philo_died(thread) || all_full(thread))
//			break ;
		if (think(thread))
			break ;
	}
	return (NULL);
}
