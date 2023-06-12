/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:40:44 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/12 08:20:15 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks input for error and returns messages
  Creates the linked list and sets the position they should be after sorting.
  Checks for duplicates,sorted or reverse sorted.
  Sorts the list printing out commands
  Deallocates both linked lists.*/
int	main(int argc, char **argv)
{
	int		result;
	t_node	*a;
	t_node	*b;

	result = ft_handle_errors(argc, argv);
	b = NULL;
	if (!result)
		return (0);
	argv++;
	argc--;
	ft_makelist(argc, argv, &a);
	set_index(a, lstsize(a));
	ft_argument_count(&a, &b);
	dealloc_list(&a, &b);
	return (0);
}
