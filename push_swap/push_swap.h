/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:39:41 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/07 10:02:37 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdbool.h>
# define ERROR "Error\n"
# include <stdlib.h>
# include <limits.h>

int		ft_handle_errors(int argc, char **argv);
int		ft_check_array(char *str);
int		ft_check_argv(char **argv);
int		ft_check_argv_str(char **argv);

typedef struct s_node {
	int				x;
	int				current_pos;
	int				price_a;
	int				price_b;
	int				index;
	struct s_node	*t_n;
	struct s_node	*next;
}	t_node;

void	ft_makelist(int argc, char **argv, t_node **list);
int		split_len(char **buf);
int		lstsize(t_node *lst);
t_node	*addnew(int x);
t_node	*lstlast(t_node *lst);
void	insert_end(t_node **lst, t_node *new);
void	lstiter(t_node *lst);
int		ft_duplicates(t_node *list);
void	create_list(t_node **list, int argc, char **argv);
void	dealloc_list(t_node **a, t_node **b);
void	swap(t_node **list);
void	sa(t_node **a, bool value);
void	sb(t_node **b, bool value);
void	ss(t_node **a, t_node **b);
void	rotate(t_node **list);
void	ra(t_node **a, bool value);
void	rb(t_node **b, bool value);
void	rr(t_node **a, t_node **b);
void	reverse_rotate(t_node **list);
void	rra(t_node **a, bool value);
void	rrb(t_node **b, bool value);
void	rrr(t_node **a, t_node **b);
void	push(t_node **dest, t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
t_node	*find_max(t_node *list);
t_node	*find_min(t_node *list);

void	ft_argument_count(t_node **a, t_node **b);
void	sort_two_params(t_node **a);
void	sort_three_params(t_node **a, bool value);
void	sort_five_params(t_node **a, t_node **b, bool value);
void	target_node(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);
void	set_current(t_node **a, t_node **b);
void	set_position(t_node *b);
void	set_price(t_node **a, t_node **b);
// void	set_best_fit(t_node **b);
// t_node	*get_best_fit(t_node *list);
void	move_nodes(t_node **a, t_node **b);
void	push_but_three(t_node **a, t_node **b);
void	set_index(t_node *a, int len);
void	rotate_both(t_node **a, t_node **b, t_node *best_fit);
void	rrotate_both(t_node **a, t_node **b, t_node *best_fit);
void	finish_rotation(t_node **list, char name, int *cost);
bool	is_sorted(t_node *a);
bool	is_reverse(t_node **a, t_node **b);
t_node	*find_aftermin(t_node *list, t_node *min);
void	push_but_three(t_node **a, t_node **b);
int		nb_abs(int nb);
void	do_move(t_node **a, t_node **b, int cost_a, int cost_b);
void	do_rotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b);
void	do_rrotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b);
void	shift_stack(t_node **a);
void	lstitera(t_node *lst);
t_node	*get_stack_before_bottom(t_node *stack);


#endif