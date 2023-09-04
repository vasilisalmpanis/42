/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dict_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:00:52 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/18 13:00:52 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*empty_env(char **argv)
{
	t_env	*lst;
	t_env	*tmp;

	lst = lst_env_node("PWD", getcwd(NULL, 0));
	tmp = lst_env_node("SHLVL", "0");
	ft_env_addback(&lst, tmp);
	tmp = lst_env_node("_", argv[0]);
	ft_env_addback(&lst, tmp);
	return (lst);
}

int	env_lst_size(t_env *env_lst)
{
	int	count;

	count = 0;
	while (env_lst)
	{
		count++;
		env_lst = env_lst->next;
	}
	return (count);
}

int	set_value_env(t_env *env, char *key, char *pwd)
{
	while (env)
	{
		if (ft_strncmp(env->key, key, ft_strlen(env->key)) == 0)
		{
			if (env->value[0])
				free(env->value);
			if (!pwd)
				env->value = ft_strdup("\0");
			else
				env->value = ft_strdup(pwd);
			if (!env->value)
				return (1);
		}
		env = env->next;
	}
	return (0);
}

char	*ft_getenv(t_env *lst, char *key)
{
	while (lst)
	{
		if (ft_strncmp(key, lst->key, ft_strlen(lst->key)) == 0
			&& ft_strlen(lst->key) == ft_strlen(key))
		{
			return (ft_strdup(lst->value));
		}
		lst = lst->next;
	}
	return (NULL);
}
