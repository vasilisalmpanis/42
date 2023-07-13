/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:21:46 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/13 12:26:16 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_mouse(int button, int x, int y, t_complex *f)
{
	int	i;

	i = 0;
	if (button == MOUSE_SCROLL_UP)
	{
		f->max_r -= (f->max_r - f->min_r) / (WIDTH) * 100;
		f->min_r = f->max_r * -1;
		f->max_i = f->max_r / 2;
		f->min_i = (f->max_r / 2) * (-1);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		f->max_r += (f->max_r - f->min_r) / (WIDTH) * 100;
		f->min_r = f->max_r * -1;
		f->max_i = f->max_r / 2;
		f->min_i = (f->max_r / 2) * (-1);
	}
	else if (button == MOUSE_CLICK_RIGHT)
		f->calc_color = polynomial;
	else if (button == MOUSE_CLICK_LEFT)
		f->calc_color = calc_color;
	draw_set(f);
	return (1);
}
