/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:39:41 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/23 15:44:04 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_error_msg(char *msg, int exit_code, int flag)
{
	if (flag)
		ft_putstr_fd(msg, 2);
	else
		perror(msg);
	exit(exit_code);
}

void	ft_check_errors(t_env **env_lst, t_cmd *cmd, char **env_array)
{
	if (!check_path_existence(*env_lst) && !(cmd->path_known))
	{
		free_stuff(env_lst, cmd, env_array);
		ft_print_error_msg("minishell: no path found\n", 126, 1);
	}
	if (!cmd->path)
	{
		free_stuff(env_lst, cmd, env_array);
		ft_print_error_msg("minishell: command not found\n", 127, 1);
	}
	if (access(cmd->path, F_OK) == -1)
	{
		free_stuff(env_lst, cmd, env_array);
		ft_print_error_msg("minishell", 127, 0);
	}
	if (access(cmd->path, X_OK) == -1)
	{
		free_stuff(env_lst, cmd, env_array);
		ft_print_error_msg("minishell", 126, 0);
	}
	if (!cmd->args)
	{
		free_stuff(env_lst, cmd, env_array);
		exit(EXIT_FAILURE);
	}
}
