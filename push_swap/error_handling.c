/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:42:07 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/13 13:13:35 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* If users gives one string split it and pass it to argv checker */
int	ft_check_array(char *str)
{
	char	**argv;
	int		result;

	if (!str)
		return (0);
	argv = ft_split(str, ' ');
	if (argv[0] == NULL)
	{
		ft_free(argv, ft_find_wc(str, ' '));
		exit(-1);
	}
	result = 0;
	if (!argv)
		return (0);
	if (ft_check_argv_str(argv))
		result = 2;
	ft_free(argv, ft_find_wc(str, ' '));
	return (result);
}

/*Only allows one + - and a digit after. Returns 0 when other than digit found*/
int	ft_check_argv_str(char **argv)
{
	int		i;
	int		j;
	bool	pm;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		pm = false;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && !pm && j == 0)
			{
				pm = 1;
				j++;
			}
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd(ERROR, 1);
				return (0);
			}
		}
	}
	return (1);
}

/*Same as argv_str but jumps over first element of argv. Could use same
function just adding one to pointer to skip program name.
Only allows one + - and a digit after. Returns 0 when other than digit found*/
int	ft_check_argv(char **argv)
{
	int		i;
	int		j;
	bool	pm;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		pm = false;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && !pm && j == 0)
			{
				pm = 1;
				j++;
			}
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd(ERROR, 1);
				return (0);
			}
		}
	}
	return (1);
}

/* Checks if arguments are one string or multiple 
If no error is found it returns 1 otherwise 0. */
int	ft_handle_errors(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (argc == 2)
		return (ft_check_array(argv[1]));
	else
	{
		return (ft_check_argv(argv));
	}
	return (1);
}
