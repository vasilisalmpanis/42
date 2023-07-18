/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:21:46 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/18 11:26:47 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_mouse(int button, int x, int y, t_var *ui)
{
	if (button == MOUSE_SCROLL_UP)
	{
		ui->f->max_r -= (ui->f->max_r - ui->f->min_r) / (WIDTH) * 50 ;
		ui->f->min_r = ui->f->max_r * -1;
		ui->f->max_i = ui->f->max_r / 2;
		ui->f->min_i = (ui->f->max_r / 2) * (-1);
		ui->f->r_origin = (((((double)x / ui->f->width) * (ui->f->max_r - \
		ui->f->min_r)) - ((ui->f->max_r - ui->f->min_r) / 2)) * 0.2 \
		+ ui->f->r_origin);
		ui->f->i_origin = (((((double)y / ui->f->height) * (ui->f->max_i - \
		ui->f->min_i)) - ((ui->f->max_i - ui->f->min_i) / 2)) * 0.2 \
		+ ui->f->i_origin);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		ui->f->max_r += (ui->f->max_r - ui->f->min_r) / (WIDTH) * 50;
		ui->f->min_r = ui->f->max_r * -1;
		ui->f->max_i = ui->f->max_r / 2;
		ui->f->min_i = (ui->f->max_r / 2) * (-1);
	}
	else if (button == MOUSE_CLICK_RIGHT)
		julia_change_c(x, y, ui);
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
	return (1);
}
