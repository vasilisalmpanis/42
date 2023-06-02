/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:39:41 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/02 10:22:28 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdbool.h>
# define ERROR "Error\n"
# include <stdlib.h>

int		ft_handle_errors(int argc, char **argv);
int		ft_check_array(char *str);
int		ft_check_argv(char **argv);
int		ft_check_argv_str(char **argv);
void	ft_makelist(int argc, char **argv);

typedef struct s_node {
	int				x;
	struct s_node	*next;
}	t_node;

int		lstsize(t_node *lst);
t_node	*addnew(int x);
t_node	*lstlast(t_node *lst);
void	insert_end(t_node **lst, t_node *new);
void	lstiter(t_node *lst);
int		ft_duplicates(t_node *list);
void	create_list(t_node **list, int argc, char **argv);
void	dealloc_list(t_node **list);

#endif