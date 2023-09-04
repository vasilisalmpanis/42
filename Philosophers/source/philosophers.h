/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:01:23 by valmpani          #+#    #+#             */
/*   Updated: 2023/09/01 13:01:28 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include "../libft/libft.h"

typedef	struct s_prog t_prog;

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				id;
	int				meals_eatten;
	int				*dead;
	size_t			last_meal;
	t_prog			*prog;
}		t_philo;

typedef struct s_prog
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				meals;
	int				dead;
	int				phil_num;
	pthread_mutex_t	is_dead;
	pthread_mutex_t	meal_proc;
	t_philo			*threads;
}		t_prog;

// TIME
int		ft_usleep(size_t millisec);
size_t	get_time(void);

// INIT_PROG
t_prog	*initialize_prog(int *num, int argc);
int		init_philo(t_prog **prog, int num);
int		*parse(char **argv, int argc);

// ROUTINE
void	*routine(void *prog);

#endif
