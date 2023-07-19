/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_no_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:36:11 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/18 14:36:11 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_shift_rate(t_var *ui, int keycode)
{
	if (keycode == KEY_5)
		key_5(ui);
}

void	key_5(t_var *ui)
{
	if (ui->f->shift_rate >= 0.1 || ui->f->shift_rate <= -1 * SHIFT_RATE)
		write(1, "Shift rate cannot be increased more\n", 37);
	else
	{
		if (ui->f->shift_rate > 0)
			ui->f->shift_rate = ui->f->shift_rate + ui->f->shift_rate / 2;
		else
			ui->f->shift_rate = ui->f->shift_rate - ui->f->shift_rate / 2;
	}
}

void	shift_mode(t_var *ui, int keycode)
{
	if (keycode == KEY_SHIFT && ui->f->shift == 0)
		ui->f->shift = 1;
	else
		ui->f->shift = 0;
}

int	handle_no_events(t_var	*ui)
{
	if (ui->f->shift == 1)
	{
		ui->f->c_r += ui->f->shift_rate * (ui->f->c_r < 2);
		ui->f->c_i += ui->f->shift_rate * (ui->f->c_i < 2);
		if ((ui->f->c_r > 2 || ui->f->c_i > 2))
		{
			ui->f->shift = 2;
			ui->f->shift_rate = -1 * ui->f->shift_rate;
		}
	}
	else if (ui->f->shift == 2)
	{
		ui->f->c_r += ui->f->shift_rate * (ui->f->c_r > -2);
		ui->f->c_i += ui->f->shift_rate * (ui->f->c_i > -2);
		if ((ui->f->c_r < -2 || ui->f->c_i < -2))
		{
			ui->f->shift = 1;
			ui->f->shift_rate = -1 * ui->f->shift_rate;
		}
	}
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
	return (1);
}
