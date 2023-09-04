/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:23:37 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/24 16:38:04 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * Function:  echo
 * --------------------
 * Echoes the arguments passed to the cmd. if the -n flag is present echo doesn't
 * print a newline.
 * @cmd Reference to the command given by lexer
 */
int	echo(t_cmd *cmd)
{
	int	i;
	int	flag;

	i = 0;
	flag = check_newline(cmd);
	while (cmd->args[i])
	{
		if ((flag == 0 && i == 0) || i > 0)
		{
			print_var(cmd->args[i]);
			if (cmd->args[i + 1] && cmd->args[i][0] != '\0')
				ft_putchar_fd(' ', 1);
		}
		i++;
	}
	if (flag == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}

int	check_newline(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->args[0])
	{
		if (cmd->args[0][0] == '-')
		{
			while (cmd->args[0][i] && cmd->args[0][i] == 'n')
				i++;
			if (cmd->args[0][i])
				return (1);
		}
	}
	return (0);
}

void	print_var(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], STDOUT_FILENO);
}
