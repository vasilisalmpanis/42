/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:42:07 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/31 09:52:24 by valmpani         ###   ########.fr       */
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
	if (!argv)
		return (0);
	result = ft_check_argv(argv);
	ft_free(argv, ft_find_wc(str, ' '));
	return (result);
}

int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
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
