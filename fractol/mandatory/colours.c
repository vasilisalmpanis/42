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

/*
 * Function:  calc_color
 * --------------------
 * @iter : number of iterations
 * Creates rgb values from the online paper
 * https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf
 * Sets the colour
 */
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

/*
 * Function:  polynomial
 * --------------------
 * @iter : number of iterations
 * Creates rgb values from the online paper
 * https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf
 * Sets the colour but now the transparent value is always zero
 */
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

/*
 * Function:  basic
 * --------------------
 * @iter : number of iterations
 * Creates rgb values from the online paper
 * Only creates the basic values
 * Not implemented
 */
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

/*
 * Function:  set_color
 * --------------------
 * @t : transparent value
 * @r : red value
 * @g : green value
 * @b : blue value
 * Creates rgb values from the online paper
 * https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf
 * Sets the colour with bitwise operations. every 8 bits for every colour
 */
int	set_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
 * Function:  change_colour
 * --------------------
 * @keycode : Code of the key pressed
 * @ui : They ui struct
 * Changes the colour depending on the key pressed
 */
void	change_colour(t_var *ui, int keycode)
{
	if (keycode == KEY_GREEN)
		ui->f->calc_color = calc_color;
	if (keycode == KEY_BLUE)
		ui->f->calc_color = polynomial;
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}
