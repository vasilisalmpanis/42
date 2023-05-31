/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:39:41 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/31 18:11:38 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdbool.h>

int		ft_handle_errors(int argc, char **argv);
int		ft_check_array(char *str);
int		ft_check_argv(char **argv);
int		ft_check_argv_str(char **argv);
void	ft_makelist(int argc, char **argv);

#endif