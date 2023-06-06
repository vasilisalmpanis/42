/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:57:52 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/06 12:42:24 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_node **list, int argc, char **argv)
{
	int		i;
	char	**buf;

	*list = NULL;
	i = 0;
	if (argc != 2)
		while (argv[++i])
			insert_end(list, addnew(ft_atoi(argv[i])));
	else
	{
		buf = ft_split(argv[1], ' ');
		while (buf[i])
		{
			insert_end(list, addnew(ft_atoi(buf[i])));
			i++;
		}
		ft_free(buf, ft_find_wc(argv[1], ' '));
	}
}

void	dealloc_list(t_node **a, t_node **b)
{
	t_node	*temp;
	t_node	*current;

	current = *a;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	a = NULL;
	current = *b;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	b = NULL;
}

void	ft_makelist(int argc, char **argv, t_node **list)
{
	*list = NULL;
	create_list(list, argc, argv);
	if (!ft_duplicates(*list))
		return ;
	if (lstsize(*list) < 2)
		return ;
	ft_putstr_fd(ERROR, 1);
	exit(1);
}

int	ft_duplicates(t_node *list)
{
	t_node	*temp;

	if (!list)
		return (0);
	while (list->next != NULL)
	{
		temp = list->next;
		while (temp != NULL)
		{
			if (list->x == temp->x)
				return (1);
			temp = temp->next;
		}
		list = list->next;
	}
	return (0);
}

void	assign_index(t_node *a, int stack_size)
{
	t_node	*ptr;
	t_node	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->x == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->x > value && ptr->index == 0)
			{
				value = ptr->x;
				highest = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}