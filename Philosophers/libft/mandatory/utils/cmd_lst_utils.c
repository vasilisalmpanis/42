/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:49:58 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/23 15:51:05 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_new_cmd(int id, char **env_paths, int exit_code)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(*node));
	if (env_paths)
		node->env_flag = 1;
	node->exit_code = exit_code;
	node->cmd_id = id;
	node->next = NULL;
	return (node);
}

void	ft_cmd_lstadd_end(t_cmd **lst, t_cmd *new)
{
	t_cmd	**ptr;

	ptr = lst;
	while (*ptr)
		ptr = &(*ptr)->next;
	*ptr = new;
}

t_file	*create_new_file(char *delim, t_token token, char *name)
{
	t_file	*node;

	node = (t_file *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(*node));
	if (name)
	{
		node->name = ft_strdup(name);
		if (!node->name)
			return (NULL);
	}
	if (delim)
	{
		node->delim = ft_strdup(delim);
		if (!node->delim)
			return (NULL);
	}
	node->token = token;
	node->next = NULL;
	return (node);
}

void	ft_file_lst_add(t_file **lst, t_file *new_file)
{
	t_file	**ptr;

	ptr = lst;
	while (*ptr)
		ptr = &(*ptr)->next;
	*ptr = new_file;
}

void	add_start_lst(t_cmd *cmd)
{
	t_cmd	*start;

	start = cmd;
	while (cmd)
	{
		cmd->start = start; 
		cmd = cmd->next;
	}
}
