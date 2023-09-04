/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_spaces_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:55:19 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/18 13:02:18 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	skip_quotes(char *input, int *i, char **new_input, int *j)
{
	char	buf;

	buf = '\0';
	if (input[*i] == '"' || input[*i] == '\'')
	{
		buf = input[*i];
		(*new_input)[(*j)++] = input[*i];
		(*i)++;
		while (input[*i] && input[*i] != buf)
		{
			(*new_input)[(*j)++] = input[*i];
			(*i)++;
		}
	}
}

void	skip_quotes2(char *input, int *i)
{
	char	buf;

	buf = '\0';
	if (input[*i] == '"' || input[*i] == '\'')
	{
		buf = input[*i];
		(*i)++;
		while (input[*i] && input[*i] != buf)
			(*i)++;
	}
}
