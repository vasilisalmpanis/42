/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:54:39 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/22 16:00:28 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	parse_integer(const char *str, int *index, int *minus)
{
	int	number;

	number = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		number = number * 10 + str[*index] - '0';
		(*index)++;
	}
	return (number * (*minus));
}

static	double	parse_decimal(const char *str, int *index)
{
	double	number;
	double	decimalfactor;

	number = 0.0;
	decimalfactor = 0.1;
	(*index)++;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		number += (str[*index] - '0') * decimalfactor;
		decimalfactor /= 10.0;
		(*index)++;
	}
	return (number);
}

double	ft_datoi(const char *str)
{
	int		index;
	int		minus;
	double	number;
	bool	hasdecimal;

	index = 0;
	minus = 1;
	number = 0.0;
	hasdecimal = false;
	while ((str[index] >= '\t' && str[index] <= '\r') || str[index] == ' ')
		index++;
	if (str[index] == '-')
	{
		minus = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	number = parse_integer(str, &index, &minus);
	if (str[index] == '.' || str[index] == ',')
	{
		hasdecimal = true;
		number += parse_decimal(str, &index);
	}
	return (number * minus);
}
