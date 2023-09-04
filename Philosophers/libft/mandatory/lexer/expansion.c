/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:43:19 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 16:33:52 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*check_expand(char *split, int i, t_env *lst, int trim_flag)
{
	char	*exp_word;

	exp_word = ft_calloc(1, 1);
	if (!exp_word)
		return (NULL);
	while (split[++i])
	{
		if (split[0] != '\'' && split[i] == '$')
		{
			if (check_expand_helper(split, &i, &exp_word, lst))
				return (NULL);
		}
		else
		{
			exp_word = ft_charjoin_mod(exp_word, split[i]);
			if (!exp_word)
				return (NULL);
		}
		if (!split[i])
			break ;
	}
	if (trim_flag)
		exp_word = trim_word(exp_word);
	return (exp_word);
}

int	check_expand_helper(char *split, int *i, char **exp_word, t_env *lst)
{
	if ((split[*i + 1] != '\0' && !ft_isspace(split[*i + 1])
			&& split[*i + 1] != '"' && split[*i + 1] != '\'' 
			&& split[*i + 1] != '}' && split[*i + 1] != ')'
			&& split[*i + 1] != ':' && split[*i + 1] != '='
			&& split[*i + 1] != '^' && split[*i + 1] != '%'
			&& !(split[*i + 1] >= '+' && split[*i + 1] <= '/')))
	{
		(*i)++;
		if (expand(split, i, exp_word, lst))
			return (1);
		(*i)--;
	}
	else 
	{
		*exp_word = ft_charjoin_mod(*exp_word, split[*i]);
		if (!(*exp_word))
			return (1);
	}
	return (0);
}

int	expand(char *split, int *i, char **exp_word, t_env *lst)
{
	char	*exp_var;

	exp_var = NULL;
	if (split[*i] && split[*i] == '$')
	{
		exp_var = find_pid(i);
		if (!exp_var)
			return (free(*exp_word), 1);
	}
	else
	{
		if (create_exp_var(split, i, lst, &exp_var))
			return (free(*exp_word), 1);
	}
	if (exp_var)
	{
		*exp_word = ft_strjoin_mod(*exp_word, exp_var);
		if (!(*exp_word))
			return (1);
	}
	free(exp_var);
	return (0);
}
