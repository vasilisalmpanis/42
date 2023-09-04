/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:59:05 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 12:40:23 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	wait_for_children(t_cmd *start)
{
	int		status;
	int		exit_code;

	status = 0;
	exit_code = 0;
	while (start && start->next)
	{
		waitpid(start->pid, NULL, 0);
		start = start->next;
	}
	if (waitpid(start->pid, &status, 0) == -1)
		return (1);
	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		if (exit_code != 0)
			return (exit_code);
	}
	return (0);
}

int	exec_builtin(t_cmd *cmd, t_env **env_lst)
{
	int	exit_code;

	exit_code = 0;
	if (!ft_strncmp(cmd->cmd, "echo", ft_strlen(cmd->cmd)) && \
			ft_strlen(cmd->cmd) == 4)
		exit_code = echo(cmd);
	else if (!ft_strncmp(cmd->cmd, "pwd", ft_strlen(cmd->cmd)) && \
			ft_strlen(cmd->cmd) == 3)
		exit_code = pwd();
	else if (!ft_strncmp(cmd->cmd, "env", ft_strlen(cmd->cmd)) && \
			ft_strlen(cmd->cmd) == 3)
		exit_code = env(*env_lst, cmd);
	else if (!ft_strncmp(cmd->cmd, "cd", ft_strlen(cmd->cmd)) && \
			ft_strlen(cmd->cmd) == 2)
		exit_code = cd_dir(cmd, *env_lst);
	else if (!ft_strncmp(cmd->cmd, "export", ft_strlen(cmd->cmd)) && \
			ft_strlen(cmd->cmd) == 6)
		exit_code = export(env_lst, cmd);
	else if (!ft_strncmp(cmd->cmd, "unset", ft_strlen(cmd->cmd)) && \
			ft_strlen(cmd->cmd) == 5)
		exit_code = unset(env_lst, cmd);
	else if (!ft_strncmp(cmd->cmd, "exit", ft_strlen(cmd->cmd)) && \
			ft_strlen(cmd->cmd) == 4)
		exit_code = exit_builtin(env_lst, cmd);
	return (exit_code);
}

char	**new_env(t_env *env_lst)
{
	char	**env_array;
	char	*temp;
	int		len;
	int		i;

	i = -1;
	len = env_lst_size(env_lst);
	env_array = ft_calloc(len + 1, sizeof(*env_array));
	if (!env_array)
		return (NULL);
	while (env_lst)
	{
		if (env_lst->value[0] != '\0')
		{
			temp = ft_strjoin(env_lst->key, "=");
			if (!temp)
				return (ft_free(env_array), NULL);
			env_array[++i] = ft_strjoin(temp, env_lst->value);
			if (!env_array[i])
				return (ft_free(env_array), NULL);
			free(temp);
		}
		env_lst = env_lst->next;
	}
	return (env_array);
}

int	check_path_existence(t_env *env_lst)
{
	while (env_lst)
	{
		if (!(ft_strncmp(env_lst->key, "PATH", ft_strlen(env_lst->key))))
			return (1);
		env_lst = env_lst->next;
	}
	return (0);
}
