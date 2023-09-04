/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:21:30 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/22 09:18:00 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * Function:  env
 * --------------------
 * Prints the env list but doesn't print the node if it doesn't have a value
 * @lst	Reference to the env list
 * @cmd Reference to the command given by lexer
 */
int	env(t_env *lst, t_cmd *cmd)
{
	t_env	*env;

	env = lst;
	if (cmd->args[0])
	{
		ft_putstr_fd("env: ", 1);
		ft_putstr_fd(cmd->args[0], 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		return (1);
	}
	while (env)
	{
		if (env->value[0] != '\0')
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (0);
}

//adds the new nodes in the end of the list. normal env adds in random places