/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:30:06 by valmpani          #+#    #+#             */
/*   Updated: 2023/09/04 18:30:09 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse(char **argv, int argc)
{
	int	*num;

	if (argc != 5 && argc != 6)
		return (1);
	if (ft_atoi(argv[1]) < 0)
		return (1);
	if (ft_atoi(argv[2]) < 60)
		return (1);
	if (ft_atoi(argv[3]) < 60)
		return (1);
	if (ft_atoi(argv[4]) < 60)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (1);
	return (0);
}

t_prog	*initialize_prog(int argc, char **argv)
{
	int		i;
	t_prog	*prog;

	prog = ft_calloc(1, sizeof(t_prog));
	if (!prog)
		return (NULL);
	prog->phil_num = ft_atoi(argv[1]);
	prog->time_to_die = ft_atoi(argv[2]);
	prog->time_to_eat = ft_atoi(argv[3]);
	prog->time_to_sleep = ft_atoi(argv[4]);
	prog->philo = malloc(sizeof(pthread_t) * prog->phil_num);
	if (argc == 6)
		prog->meals = ft_atoi(argv[5]);
	else
		prog->meals = -1;
	if (pthread_mutex_init(&prog->is_dead, NULL) != 0 || \
		pthread_mutex_init(&prog->meal_proc, NULL) != 0 || \
		pthread_mutex_init(&prog->print, NULL) != 0)
		return (NULL);
	if (init_philo(&prog, prog->phil_num))
		return (NULL);
	return (prog);
}

int	init_philo(t_prog **prog, int num)
{
	int	i;

	(*prog)->threads = malloc(num * sizeof(t_philo));
	if (!(*prog)->threads)
		return (1);
	i = -1;
	while (++i < num)
	{
		(*prog)->threads[i].id = i;
		(*prog)->threads[i].left_fork = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init((*prog)->threads[i].left_fork, NULL) != 0)
			return (1);
		(*prog)->threads[i].dead = &(*prog)->dead;
		(*prog)->threads[i].prog = (*prog);
		(*prog)->threads[i].meals_eatten = 0;
		(*prog)->threads[i].last_meal = 0;
	}
	i = -1;
	while (++i < num)
	{
		(*prog)->threads[i].right_fork = (*prog)->threads[(i + 1) % num].left_fork;
	}
	(*prog)->start_time = get_time();
	i = -1;
	while (++i < num)
	{
		pthread_create(&(*prog)->philo[i], NULL, routine,
			(void *)(&(*prog)->threads[i]));
	}
	return (0);
}
