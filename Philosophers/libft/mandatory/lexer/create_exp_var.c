/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_exp_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:32:59 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/24 10:58:54 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	create_exp_var(char *split, int *i, t_env *lst, char **exp_var)
{
	int		offset;
	int		start;
	char	*temp;

	start = *i;
	offset = 0;
	temp = NULL;
	while (split[*i] && split[*i] != '"' && split[*i] != '\''
		&& split[*i] != '}' && split[*i] != ')' && split[*i] != '$'
		&& !ft_isspace(split[*i]))
		(*i)++;
	offset = calc_offset(split, start, i);
	if (offset == -1)
		return (1);
	temp = ft_substr(split, start + offset, *i - start - (2 * offset));
	if (!temp)
		return (1);
	if (determine_exp_var(temp, lst, exp_var))
		return (free(temp), 1);
	free(temp);
	return (0);
}

int	determine_exp_var(char *temp, t_env *lst, char **exp_var)
{
	if (temp[0] == '(' && temp[1] == '(')
	{
		*exp_var = ft_strdup("You can calculate in your head");
		if (!(*exp_var))
			return (1);
	}
	else if (ft_isdigit(temp[0]) || temp[0] == '@')
	{
		*exp_var = ft_strdup(temp + 1);
		if (!(*exp_var))
			return (1);
	}
	else if (temp[0] == '?')
	{
		*exp_var = find_exit_code(temp, lst);
		if (!(*exp_var))
			return (1);
	}
	else
		if (find_exp_var(temp, exp_var, lst))
			return (1);
	return (0);
}

int	find_exp_var(char *temp, char **exp_var, t_env *lst)
{
	char	*temp2;
	char	*temp3;
	int		i;

	i = -1;
	temp2 = ft_calloc(1, 1);
	*exp_var = NULL;
	while (temp[++i])
	{
		temp2 = ft_charjoin_mod(temp2, temp[i]);
		if (!temp2)
			return (1);
		temp3 = ft_getenv(lst, temp2);
		if (temp3)
			break ;
	}
	free(temp2);
	if (temp3 && !(ft_isalnum(temp[i + 1])) && temp[i + 1] != '_')
	{
		*exp_var = ft_strjoin(temp3, &temp[i + 1]);
		free(temp3);
		if (!(*exp_var))
			return (1);
	}
	return (0);
}

char	*find_exit_code(char *temp, t_env *lst)
{
	char	*temp2;
	char	*exp_var;
	t_env	*tmp;

	while (lst)
	{
		if (ft_strncmp("EC", lst->key, ft_strlen(lst->key)) == 0
			&& ft_strlen(lst->key) == 2)
			tmp = lst;
		lst = lst->next;
	}
	temp2 = ft_itoa(tmp->ec);
	if (!temp2)
		return (NULL);
	if (temp[1])
	{
		exp_var = ft_strjoin(temp2, &temp[1]);
		free(temp2);
	}
	else
		exp_var = temp2;
	return (exp_var);
}

char	*find_pid(int *i)
{
	char	*exp_var;

	(*i)++;
	exp_var = ft_itoa(67672);
	if (!exp_var)
		return (NULL);
	return (exp_var);
}
