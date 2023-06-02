/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:40:44 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/02 14:37:24 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		result;
	t_node	*a;

	result = ft_handle_errors(argc, argv);
	if (!result)
		return (0);
	ft_makelist(argc, argv, &a);
	dealloc_list(&a);
	return (0);
}
