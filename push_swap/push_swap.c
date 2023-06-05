/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:40:44 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/05 12:53:50 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		result;
	t_node	*a;
	t_node	*b;

	result = ft_handle_errors(argc, argv);
	b = NULL;
	if (!result)
		return (0);
	ft_makelist(argc, argv, &a);
	ft_argument_count(&a, &b);
	dealloc_list(&a, &b);
	return (0);
}
