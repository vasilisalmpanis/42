/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:58:26 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/24 16:51:54 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_key(t_env *env, char *key)
{
	char	*pwd;

	pwd = NULL;
	while (env)
	{
		if (ft_strncmp(env->key, key, ft_strlen(env->key)) == 0)
		{
			pwd = ft_strdup(env->value);
			if (!pwd)
				return (NULL);
		}
		env = env->next;
	}
	return (pwd);
}

int	ft_change_env(t_env *env, char *target_dir)
{
	char	*pwd;

	pwd = find_key(env, "PWD");
	if (set_value_env(env, "OLDPWD", pwd))
		return (1);
	if (set_value_env(env, "PWD", target_dir))
		return (1);
	if (pwd)
		free(pwd);
	return (0);
}

int	cd_home(t_cmd *cmd, t_env *env)
{
	char		*home;

	if (cmd->args[0] != NULL)
		return (1);
	if (cmd->args[0] == NULL)
	{
		home = getenv("HOME");
		if (!home)
			return (ft_putstr_fd("error\n", STDERR_FILENO), 1);
		ft_change_env(env, home);
		chdir(home);
	}
	return (0);
}

/*
 * Function:  cd
 * --------------------
 * Changes directory to the absolute or relative path passed to it.
 * If cmd has more than one argument it is supposed to display an error message
 * and set the error code accordingly
 * @cmd Reference to the command given by lexer
 */
int	cd_dir(t_cmd *cmd, t_env *env)
{
	if (!cd_home(cmd, env))
		return (1);
	else
	{
		if (ft_strncmp(cmd->args[0], "~", ft_strlen(cmd->args[0])) == 0)
			return (ft_putstr_fd("cd: ~: Not handled by minishell\n", 2), 1);
		else
		{
			return (change_directory(cmd, env));
		}
	}
}

int	change_directory(t_cmd *cmd, t_env *env)
{
	char	*home;

	if (chdir(cmd->args[0]) == 0)
	{
		home = getcwd(NULL, 0);
		if (!home)
		{
			ft_putstr_fd(CD1, 2);
			ft_putstr_fd(CD2, 2);
			home = ft_strdup(getenv("HOME"));
		}
		ft_change_env(env, home);
		free(home);
	}
	else
		return (ft_putstr_fd(NO_CD, 2), 1);
	return (0);
}
