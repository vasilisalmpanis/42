/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:38:20 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/24 10:39:24 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2023/08/21 14:40:26 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strisnum(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_exit(char *str);

int	exit_builtin(t_env **lst, t_cmd *cmd)
{
	int	exit_code;

	if (!cmd)
	{
		ft_env_free(lst);
		exit(0);
	}
	if (cmd->args[0] == NULL)
	{
		exit_code = cmd->exit_code;
		free_env_cmd_ex(lst, cmd);
		exit(exit_code);
	}
	if (cmd->args[1])
		return (ft_putstr_fd(" too many arguments\n", STDERR_FILENO), 1);
	else
	{
		exit_code = check_exit(cmd->args[0]);
		if (exit_code == -1)
			exit_code = 255;
		free_env_cmd_ex(lst, cmd);
		exit(exit_code);
	}
	return (0);
}

int	check_exit(char *str)
{
	char	*temp;
	int		is_neg;

	temp = "9223372036854775808";
	is_neg = 0;
	if (str[0] == '-')
	{
		temp = "9223372036854775809";
		is_neg = 1;
	}
	if (!ft_strisnum(str) || ft_strncmp(str + \
			is_neg, temp, ft_strlen(temp)) >= 0)
	{
		ft_putstr_fd(" numeric argument required\n", STDERR_FILENO);
		return (-1);
	}
	else
	{
		return (ft_atoi(str));
	}
}
