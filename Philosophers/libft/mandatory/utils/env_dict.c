/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:57:46 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/23 15:51:22 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * Function:  *lst_env_node
 * --------------------
 * Creates a new node for the environmental variable
 * checking if value is null or not and if the key is "SHLVL" it adds 1 to it
 * by using atoi and itoa.
 * @key	String value for key of the pair
 * @value String value for value of the pair
 */
t_env	*lst_env_node(char *key, char *value)
{
	t_env	*node;
	int		temp;

	node = (t_env *)malloc(sizeof(t_env));
	ft_bzero(node, sizeof(*node));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (ft_strncmp(node->key, "SHLVL", ft_strlen(node->key)) == 0)
	{
		temp = ft_atoi(value);
		temp += 1;
		node->value = ft_itoa(temp);
	}
	else
	{
		if (!value)
			node->value = ft_strdup("");
		else
			node->value = ft_strdup(value);
	}
	node->next = NULL;
	return (node);
}

/*
 * Function:  *ft_env_addback
 * --------------------
 * Adds the new node in the end of the list.
 * If the key already exists it updates the value and
 * frees the previous one.
 * @lst	Reference to the env list
 * @new Reference to the new node to be added.
 */
void	ft_env_addback(t_env **lst, t_env *new)
{
	t_env	**ptr;

	ptr = lst;
	while (*ptr)
	{
		if (ft_strncmp((*ptr)->key, new->key, ft_strlen(new->key)) == 0 \
		&& ft_strlen(new->key) == ft_strlen((*ptr)->key))
		{
			if ((*ptr)->value)
				free((*ptr)->value);
			if (!new->value)
				(*ptr)->value = ft_strdup("");
			else
				(*ptr)->value = ft_strdup(new->value);
			free(new->value);
			free(new->key);
			free(new);
			return ;
		}
		ptr = &(*ptr)->next;
	}
	*ptr = new;
}

/*
 * Function:  ft_env_free
 * --------------------
 * Deallocates all the previously allocated nodes of the list
 * @lst	Reference to the env list
 */
void	ft_env_free(t_env **lst)
{
	t_env	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		if (temp->key)
			free(temp->key);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}

/*
 * Function:  ft_env_remove
 * --------------------
 * Removes the node from the list
 * If the key already exists it updates the value and
 * @begin_list	Address of HEAD
 * @key The key to be removed
 */
void	ft_env_remove(t_env **begin_list, char *key)
{
	t_env	**ptr;
	t_env	*temp;

	ptr = begin_list;
	while (*ptr)
	{
		if (ft_strncmp(key, (*ptr)->key, ft_strlen((*ptr)->key)) == 0)
		{
			temp = *ptr;
			*ptr = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			return ;
		}
		else
			ptr = &((*ptr)->next);
	}
}

/*
 * Function:  *create_env
 * --------------------
 * Creates the env list by spliting where the "=" is.
 * This has to be changed with the new function for export to avoid
 * problems when bash or minishell are executed again and again.
 * @en The env list passed from the program.
 */
t_env	*create_env(char **en, char **argv)
{
	t_env	*lst;
	t_env	*tmp;
	char	*temp[2];
	char	*sign;
	int		i;

	if (!en)
		return (empty_env(argv));
	i = -1;
	lst = NULL;
	while (en[++i])
	{
		sign = ft_strchr(en[i], '=');
		temp[0] = ft_substr(en[i], 0, sign - en[i]);
		temp [1] = ft_substr(sign + 1, 0, ft_strlen(en[i]) - (sign - en[i]));
		tmp = lst_env_node(temp[0], temp[1]);
		ft_env_addback(&lst, tmp);
		free(temp[0]);
		free(temp[1]);
	}
	tmp = lst_env_node("EC", NULL);
	ft_env_addback(&lst, tmp);
	return (lst);
}
