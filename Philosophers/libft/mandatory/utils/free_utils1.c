/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:03:16 by mamesser          #+#    #+#             */
/*   Updated: 2023/08/24 16:31:44 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_cmd_lex_env(t_cmd **cmd_lst, t_lex **lex_lst, char **env_paths)
{
	ft_cmd_lst_free(cmd_lst);
	ft_lst_free(lex_lst);
	if (env_paths)
		ft_free(env_paths);
}

void	ft_cmd_lst_free(t_cmd **lst)
{
	t_cmd	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		if (temp->cmd)
			free(temp->cmd);
		if (temp->path)
			free(temp->path);
		if (temp->args)
			ft_free(temp->args);
		if (temp->file)
			ft_free_file_lst(&(temp->file));
		if (temp->hd_file)
			free(temp->hd_file);
		free(temp);
	}
}

void	ft_cmd_lst_free_child(t_cmd *lst)
{
	t_cmd	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		if (temp->cmd)
			free(temp->cmd);
		if (temp->path)
			free(temp->path);
		if (temp->args)
			ft_free(temp->args);
		if (temp->file)
			ft_free_file_lst(&(temp->file));
		if (temp->hd_file)
			free(temp->hd_file);
		free(temp);
	}
}

void	ft_free_file_lst(t_file **lst)
{
	t_file	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		if (temp->name)
			free(temp->name);
		if (temp->delim)
			free(temp->delim);
		free(temp);
	}
}

void	ft_lst_free(t_lex **lst)
{
	t_lex	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}
