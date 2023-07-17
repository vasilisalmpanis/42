/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:55:57 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/17 17:26:43 by valmpani         ###   ########.fr       */
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
	i = ((float)iter) / M_I;
	r = 9 * (1 - i) * i * i * i * 255;
	g = 15 * (1 - i) * (1 - i) * i * i * 255;
	b = 8.5 * (1 - i) * (1 - i) * (1 - i) * i * 255;
	return (set_color(r, g, b, 0));
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

void	change_colour(t_var *ui, int keycode)
{
	if (keycode == KEY_GREEN)
		ui->f->calc_color = calc_color;
	if (keycode == KEY_BLUE)
		ui->f->calc_color = polynomial;
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}
