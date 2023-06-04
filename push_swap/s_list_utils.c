/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:57:52 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/04 16:27:46 by valmpani         ###   ########.fr       */
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

void	dealloc_list(t_node **list)
{
	t_node	*temp;
	t_node	*current;

	current = *list;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	list = NULL;
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
