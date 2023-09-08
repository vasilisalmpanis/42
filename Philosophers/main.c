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

void	destroy_prog(t_prog *prog)
{
	int	i;

	i = -1;
	while (++i < prog->phil_num)
	{
		pthread_mutex_destroy(prog->threads[i].right_fork);
		free(prog->threads[i].right_fork);
	}
	free(prog->threads);
	free(prog->philo);
	pthread_mutex_destroy(&prog->is_dead);
	pthread_mutex_destroy(&prog->meal_proc);
	pthread_mutex_destroy(&prog->print);
	free(prog);
}

int	main(int argc, char **argv)
{
	t_prog	*prog;
	int		num;
	int		i;

	num = parse(argv, argc);
	if (num)
		return (printf(PARSE"\n"), 1);
	prog = initialize_prog(argc, argv);
	if (!prog)
		return (1);
	i = -1;
	ft_usleep(50);
	while (1)
	{
		if (check_is_dead(prog) || check_if_full(prog))
			break ;
	}
	join_threads(prog);
	destroy_prog(prog);
	return (0);
}
