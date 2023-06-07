/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:36:57 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/07 09:29:40 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*addnew(int x)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->x = x;
	node->next = NULL;
	node->t_n = NULL;
	return (node);
}

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	insert_end(t_node **lst, t_node *new)
{
	if (*lst == NULL && new)
		*lst = new;
	else if (lstlast(*lst))
	{
		lstlast(*lst)->next = new;
	}
}

int	lstsize(t_node *lst)
{
	int	length;

	length = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		length++;
		lst = lst->next;
	}
	return (length + 1);
}

// void	lstiter(t_node *lst)
// {
// 	t_node	*current;

// 	if (!lst)
// 		return ;
// 	current = lst;
// 	while (current != NULL)
// 	{
// 		ft_putstr_fd("list :",1 );
// 		ft_putnbr_fd(current->x, 1);
// 		ft_putstr_fd("target ->",1 );
// 		ft_putnbr_fd(current->t_n->x, 1);
// 		ft_putstr_fd(" target position ->",1 );
// 		ft_putnbr_fd(current->t_n->current_pos, 1);
// 		ft_putstr_fd(" Price ->",1 );
// 		ft_putnbr_fd(nb_abs(current->price_a) + nb_abs(current->price_b), 1);
// 		ft_putchar_fd('\n', 1);
// 		current = current->next;
// 	}
// }

// void	lstitera(t_node *lst)
// {
// 	t_node	*current;

// 	if (!lst)
// 		return ;
// 	current = lst;
// 	while (current != NULL)
// 	{
// 		ft_putstr_fd("list :", 1);
// 		ft_putnbr_fd(current->x, 1);
// 		ft_putchar_fd('\n', 1);
// 		current = current->next;
// 	}
// }
