/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:34:18 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 11:34:53 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*trim_word(char *exp_word)
{
	char	*trimmed_word;

	if (exp_word[0] == '"')
		trimmed_word = ft_strtrim(exp_word, "\"");
	else if (exp_word[0] == '\'')
		trimmed_word = ft_strtrim(exp_word, "'");
	else
		return (exp_word);
	if (!trimmed_word)
		return (free(exp_word), NULL);
	free(exp_word);
	return (trimmed_word);
}

int	calc_offset(char *split, int start, int *i)
{
	int	offset;

	offset = 0;
	if ((split[start] == '{' && split[*i] == '}')
		|| (split[start] == '(' && split[*i] == ')'))
	{
		offset++;
		(*i)++;
	}
	if (split[start + 1] == '{')
	{
		offset = -1;
		ft_putstr_fd("Error: Bad syntax near '{'\n", 2);
	}
	return (offset);
}

char	*remove_quotes(char *split, int i, int j)
{
	int		count;
	char	buf;
	char	*trimmed_word;

	buf = '\0';
	if (split[0] == '\'' || split[0] == '\"')
		return (ft_strdup(split));
	count = count_rm_quotes(split);
	if (count == -1)
		return (ft_strdup(split));
	trimmed_word = ft_calloc(count + 1, sizeof(char));
	if (!trimmed_word)
		return (NULL);
	while (split[i])
	{
		if (split[i] == '\'' || split[i] == '\"')
		{
			buf = split[i++];
			while (split[i] && split[i] != buf)
				trimmed_word[j++] = split[i++];
		}
		else
			trimmed_word[j++] = split[i];
		if (split[i])
			i++;
	}
	return (trimmed_word);
}

int	count_rm_quotes(char *split)
{
	int		count;
	char	buf;
	int		i;

	i = 0;
	count = ft_strlen(split);
	buf = '\0';
	while (split[i])
	{
		if (split[i] == '\'' || split[i] == '\"')
		{
			buf = split[i++];
			count -= 2;
			while (split[i] && split[i] != buf)
				i++;
			if (!split[i])
				return (-1);
		}
		if (split[i])
			i++;
	}
	return (count);
}
