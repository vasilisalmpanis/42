/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:57:52 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/12 08:20:51 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_node **list, int argc, char **argv, long int i)
{
	int			index;
	char		**buf;

	*list = NULL;
	index = -1;
	if (argc != 1)
	{
		while (argv[++index])
		{
			i = ft_atoi(argv[index]);
			if (i > INT_MAX || i < INT_MIN)
			{
				ft_putstr_fd("Error\n", 1);
				dealloc_list(list, NULL);
				exit(1);
			}
			insert_end(list, addnew(i));
		}
	}
	else
	{
		buf = ft_split(argv[0], ' ');
		create_list(list, ft_find_wc(argv[0], ' ') + 1, buf, i);
		ft_free(buf, ft_find_wc(argv[0], ' '));
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
	if (b == NULL)
		return ;
	current = *b;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	b = NULL;
}

/* Create the list and check for duplicates and small length
if everything goes well we return other wise we print error. */
void	ft_makelist(int argc, char **argv, t_node **list)
{
	long int	i;

	i = 0;
	*list = NULL;
	create_list(list, argc, argv, i);
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
