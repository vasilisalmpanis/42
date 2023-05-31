/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:42:07 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/31 10:38:31 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_array(char *str)
{
	char	**argv;
	int		result;

	if (!str)
		return (0);
	argv = ft_split(str, ' '); 	// FREE ME!
	result = 0;
	if (!argv)
		return (0);
	if (ft_check_argv_str(argv))
		result = 2;
	ft_free(argv, ft_find_wc(str, ' '));
	return (result);
}

int	ft_check_argv_str(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j-1] == ' ')
			{
				j++;
			}
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
		}
	}
	return (1);
}

int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		ft_putstr_fd(argv[i], 1);
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j-1] == ' ')
			{
				j++;
			}
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
		}
	}
	return (1);
}

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
