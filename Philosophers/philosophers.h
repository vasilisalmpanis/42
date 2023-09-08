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
# include <string.h>
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define FIRST	"has taken a fork"
# define SECOND	"has taken a fork"
# define DIED "died"
# define PARSE "Parsing error please give the correct parameters."

typedef struct s_prog	t_prog;

typedef struct s_philo
{
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
	int				all_fed;
	int				phil_num;
	pthread_mutex_t	is_dead;
	pthread_mutex_t	meal_proc;
	pthread_mutex_t	print;
	pthread_t		*philo;
	t_philo			*threads;
}		t_prog;

// TIME
int		ft_usleep(size_t millisec);
size_t	get_time(void);

// INIT_PROG
t_prog	*initialize_prog(int argc, char **argv);
int		init_philo(t_prog **prog, int num);
int		parse(char **argv, int argc);

// ROUTINE
void	*routine(void *prog);
int		eat(t_philo *thread);

// CHECK_PHILO
int		check_is_dead(t_prog *prog);
int		check_if_full(t_prog *prog);
int		join_threads(t_prog *prog);
void	print_message(t_philo *thread, char *message);

int		take_forks(t_philo *thread);
int		philo_died(t_philo *thread);
int		think(t_philo *thread);
void	update_meal_time(t_philo *thread);

// LIBFT
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

#endif
