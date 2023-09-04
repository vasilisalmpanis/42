/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_cmd_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:56:18 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 15:48:15 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	set_cmd_name(t_lex **lst, t_cmd *new_cmd)
{
	if (new_cmd->builtin == 1)
	{
		new_cmd->cmd = strdup((*lst)->value);
		if (!new_cmd->cmd)
			return (1);
	}
	return (0);
}

int	check_for_builtin(t_lex **lst, t_cmd *new_cmd)
{
	if (!(ft_strncmp((*lst)->value, "echo", ft_strlen((*lst)->value)))
		&& ft_strlen((*lst)->value) == 4)
		new_cmd->builtin = 1;
	else if (!(ft_strncmp((*lst)->value, "cd", ft_strlen((*lst)->value)))
		&& ft_strlen((*lst)->value) == 2)
		new_cmd->builtin = 1;
	else if (!(ft_strncmp((*lst)->value, "pwd", ft_strlen((*lst)->value)))
		&& ft_strlen((*lst)->value) == 3)
		new_cmd->builtin = 1;
	else if (!(ft_strncmp((*lst)->value, "export", ft_strlen((*lst)->value)))
		&& ft_strlen((*lst)->value) == 6)
		new_cmd->builtin = 1;
	else if (!(ft_strncmp((*lst)->value, "unset", ft_strlen((*lst)->value)))
		&& ft_strlen((*lst)->value) == 5)
		new_cmd->builtin = 1;
	else if (!(ft_strncmp((*lst)->value, "env", ft_strlen((*lst)->value)))
		&& ft_strlen((*lst)->value) == 3)
		new_cmd->builtin = 1;
	else if (!(ft_strncmp((*lst)->value, "exit", ft_strlen((*lst)->value)))
		&& ft_strlen((*lst)->value) == 4)
		new_cmd->builtin = 1;
	return (set_cmd_name(lst, new_cmd));
}

void	check_for_path(t_lex **lex_lst, t_cmd *new_cmd)
{
	int	i;

	i = -1;
	while (((*lex_lst)->value)[++i])
	{
		if (((*lex_lst)->value)[i] == '/')
		{
			new_cmd->path_known = 1;
			while (((*lex_lst)->value)[i + 2])
			{
				if (((*lex_lst)->value)[i] == '.'
					&& ((*lex_lst)->value)[i + 1] == 's'
					&& ((*lex_lst)->value)[i + 2] == 'h')
				{
					new_cmd->is_sh_script = i + 3;
					return ;
				}
				i++;
			}
		}
	}
}

int	get_cmd_name(t_lex **lex_lst, t_cmd *new_cmd)
{
	char	*temp;

	if (!(new_cmd->path_known))
	{
		new_cmd->cmd = ft_strdup((*lex_lst)->value);
		if (!new_cmd->cmd)
			return (1);
	}
	else
	{
		temp = ft_strrchr((*lex_lst)->value, '/');
		temp++;
		new_cmd->cmd = strdup(temp);
		if (!new_cmd->cmd)
			return (1);
	}
	return (0);
}

int	get_path_name(t_cmd *new_cmd, char **env_paths)
{
	char	*cmd_path;
	char	*cmd_mod;
	int		i;

	i = 0;
	cmd_mod = ft_strjoin("/", new_cmd->cmd);
	if (!cmd_mod)
		return (1);
	while (env_paths && env_paths[i])
	{
		cmd_path = ft_strjoin(env_paths[i], cmd_mod);
		if (!cmd_path)
			return (free(cmd_mod), 1);
		if (access(cmd_path, X_OK) == 0)
		{
			new_cmd->path = cmd_path;
			return (free(cmd_mod), 0);
		}
		free(cmd_path);
		i++;
	}
	free(cmd_mod);
	return (0);
}
