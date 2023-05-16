/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:09:51 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/16 10:54:19 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int		length;
	t_list	*current;

	if (!lst)
		return ;
	length = ft_lstsize(lst);
	current = lst;
	while (length > 0)
	{
		current = lst;
		lst = current->next;
		f(current->content);
		length--;
	}
}
