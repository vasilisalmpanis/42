/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:23:07 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/19 16:11:45 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_specifier(char *c, va_list arg, int *length)
{
	if (*(c + 1) == 'c')
		ft_character(va_arg(arg, int), length);
	else if (*(c + 1) == 's')
		ft_putstr(va_arg(arg, char *), length);
	else if (*(c + 1) == 'p')
		ft_putptr((unsigned long)va_arg(arg, void *), length);
	else if (*(c + 1) == '%')
	{
		ft_character('%', length);
	}
	else
		ft_printnbr(*(c + 1), va_arg(arg, int), length);
}

void	ft_find_specifier(char *str, va_list arg, int *length)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_check_specifier(str + i, arg, length);
			i += 2;
		}
		else
		{
			ft_character(str[i], length);
			i++;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	char	*cp;
	int		length;

	cp = (char *)str;
	length = 0;
	if (!*cp)
	{
		return (0);
	}
	va_start(ptr, str);
	ft_find_specifier(cp, ptr, &length);
	va_end(ptr);
	return (length);
}

// int main()
// {
// 	int	i;
// 	// void *str;
// 	i = ft_printf("%d\n", ft_printf("\001\002\007\v\010\f\r\n"));
// 	printf("%d\n", printf("\001\002\007\v\010\f\r\n"));
// 	// i = ft_printf("%u %d\n", 4294967295, 12345);
// 	if (printf("%d\n", printf("\001\002\007\v\010\f\r\n")) != i)
// 	{
// 		printf("Error");
// 	}
// 	else
// 		printf("Success");
// 	// printf("Hello my name is %s\n %X\n", "marcel", -12345);
// 	return (0);
// }
