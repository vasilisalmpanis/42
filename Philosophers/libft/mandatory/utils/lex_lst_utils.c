/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:51:42 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/24 17:19:11 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lex	*ft_new_tk(void *value, t_token token, int pos)
{
	t_lex	*node;

	node = (t_lex *)malloc(sizeof(t_lex));
	if (!node)
		return (NULL);
	node->value = ft_strdup(value);
	if (!node->value)
		return (free(node), NULL);
	node->token = token;
	node->pos = pos;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_end(t_lex **lst, t_lex *new)
{
	t_lex	**ptr;

	ptr = lst;
	while (*ptr)
		ptr = &(*ptr)->next;
	*ptr = new;
}

int	ft_check_lex(t_lex *lst)
{
	while (lst)
	{
		if (lst->value[0] != '\0')
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_token_err(char *word)
{
	int	i;
	int	num_ops;

	i = -1;
	num_ops = 0;
	if (word[0] == '\'' || word[0] == '"')
		return (0);
	while (word[++i])
	{
		if (word[i] == '<' || word[i] == '>')
			num_ops++;
	}
	if (num_ops > 2)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		return (1);
	}
	return (0);
}

int	check_token_pipe_err(t_lex *lst, t_lex *lst_start)
{
	int	count;

	while (lst)
	{
		count = 0;
		if (lst->token == TK_PIPE)
		{
			while (lst && lst->token == TK_PIPE)
			{
				count++;
				lst = lst->next;
			}
			if (count > 1)
			{
				ft_putstr_fd("minishell: syntax err near unexpected token\n", 2);
				return (ft_lst_free(&lst_start), 1);
			}
		}
		if (lst)
			lst = lst->next;
	}
	return (0);
}
