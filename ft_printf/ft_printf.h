/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:39:42 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/24 18:59:52 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_find_specifier(char *str, va_list arg, int *length);
void	ft_check_specifier(char *c, va_list arg, int *length);
void	ft_character(int c, int *length);
void	ft_putstr(char *c, int *length);
void	ft_putptr(unsigned long arg, int *length);
void	ft_hexa(unsigned long arg, int *length);
void	ft_printnbr(char c, int arg, int *length);
void	ft_putnbrhex(char c, unsigned int arg, char *base, int *length);
void	ft_putunsigned(unsigned int nbr, char *base, int *length);

#endif