/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:57:43 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/15 20:16:14 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		length;
	t_list	*current;

	if (!*lst)
		return ;
	length = ft_lstsize(*lst);
	while (length > 0)
	{
		current = *lst;
		*lst = current->next;
		ft_lstdelone(current, del);
		length--;
	}
}
