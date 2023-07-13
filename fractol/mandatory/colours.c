/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:55:57 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/13 14:43:04 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calc_color(int iter)
{
	int		r;
	int		g;
	int		b;
	int		colour;
	double	i;

	if (iter == 1)
		return (set_color(0, 0, 0, 0));
	colour = 0;
	i = ((float)iter / 1.5) / M_I;
	r = 9 * (1 - i) * i * i * i * 255;
	g = 15 * (1 - i) * (1 - i) * i * i * 255;
	b = 8.5 * (1 - i) * (1 - i) * (1 - i) * i * 255;
	return (set_color(0, r, g, b));
}

int	polynomial(int iter)
{
	int		r;
	int		g;
	int		b;
	int		colour;
	double	i;

	if (iter == 1)
		return (set_color(0, 0, 0, 0));
	colour = 0;
	i = ((float)iter) / M_I;
	r = 9 * (1 - i) * i * i * i * 255;
	g = 15 * (1 - i) * (1 - i) * i * i * 255;
	b = 8.5 * (1 - i) * (1 - i) * (1 - i) * i * 255;
	return (set_color(0, r, g, b));
}

int	basic(int iter)
{
	int		r;
	int		g;
	int		b;

	if (iter == 1)
		return (set_color(0, 0, 0, 0));
	r = iter % 256;
	g = (iter * 2) % 256;
	b = (iter * 3) % 256;
	return (set_color(0, r, g, b));
}

int	set_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
