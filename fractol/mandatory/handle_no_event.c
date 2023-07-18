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
		ui->f->c_r += SHIFT_RATE * (ui->f->c_r < 2);
		ui->f->c_i += SHIFT_RATE * (ui->f->c_i < 2);
		mlx_clear_window(ui->f->mlx, ui->f->win);
		draw_window(ui);
	}
	return (1);
}
