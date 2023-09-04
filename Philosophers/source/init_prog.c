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

int	*parse(char **argv, int argc)
{
	int	*num;

	if (argc != 5 && argc != 6)
		return (NULL);
	num = ft_calloc((argc - 1) , sizeof(int));
	if (!num)
		return (NULL);
	num[0] = ft_atoi(argv[1]);
	if (num[0] < 0)
		return (free(num), NULL);
	num[1] = ft_atoi(argv[2]);
	if (num[1] < 0)
		return (free(num), NULL);
	num[2] = ft_atoi(argv[3]);
	if (num[2] < 0)
		return (free(num), NULL);
	num[3] = ft_atoi(argv[4]);
	if (num[3] < 0)
		return (free(num), NULL);
	if (argc == 6)
	{
		num[4] = ft_atoi(argv[5]);
		if (num[4] < 0)
			return (free(num), NULL);
	}
	return (num);
}

t_prog	*initialize_prog(int *num, int argc)
{
	int		i;
	t_prog	*prog;

	prog = ft_calloc(1, sizeof(t_prog));
	if (!prog)
		return (free(num), NULL);
	prog->phil_num = num[0];
	prog->time_to_eat = num[1];
	prog->time_to_sleep = num[2];
	prog->time_to_die = num[3];
	if (argc == 6)
		prog->meals = num[4];
	else
		prog->meals = -1;
	if (pthread_mutex_init(&prog->is_dead, NULL) != 0 || \
		pthread_mutex_init(&prog->meal_proc, NULL) != 0)
		return (free(num), NULL);
	if (init_philo(&prog, num[0]))
		return (free(num), NULL);
	return (free(num), prog);
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
		(*prog)->threads[i].right_fork = malloc(sizeof(pthread_mutex_t));
		(*prog)->threads[i].left_fork = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init((*prog)->threads[i].right_fork, NULL) != 0
			|| pthread_mutex_init((*prog)->threads[i].left_fork, NULL) != 0)
			return (1);
		(*prog)->threads[i].dead = &(*prog)->dead;
		(*prog)->threads[i].prog = (*prog);
		if (pthread_create(&(*prog)->threads[i].philo, NULL,
				routine, (void *)(&(*prog)->threads[i].philo)) != 0)
		{
			perror("thread\n");
			return (1);
		}
	}
	return (0);
}
