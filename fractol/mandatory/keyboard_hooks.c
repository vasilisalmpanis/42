/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:04:30 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/18 11:54:58 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_input(int keycode, t_var *ui)
{
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		change_max_it(ui, keycode);
	else if (keycode == KEY_R)
		reset_view(ui);
	else if (keycode == KEY_BLUE || keycode == KEY_GREEN)
		change_colour(ui, keycode);
	else if (keycode == KEY_ESCAPE)
		ft_end(ui);
	else if (keycode == KEY_UP || keycode == KEY_DOWN \
			|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_view(keycode, ui);
	else if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3)
		change_set(ui, keycode);
	return (1);
}

void	change_set(t_var *ui, int keycode)
{
	if ((keycode == KEY_1 && ui->set != draw_mandelbrot) \
			|| (keycode == KEY_2 && ui->set != draw_julia) \
			|| (keycode == KEY_3 && ui->set != draw_bs))
	{
		ui->f->max_r = 2.5;
		ui->f->min_r = -2.5;
		ui->f->max_i = 1.25;
		ui->f->min_i = -1.25;
		ui->f->r_origin = 0.0;
		ui->f->i_origin = 0.0;
	}
	if (keycode == KEY_1 && ui->set)
		ui->set = draw_mandelbrot;
	else if (keycode == KEY_2)
		ui->set = draw_julia;
	else if (keycode == KEY_3)
		ui->set = draw_bs;
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}

void	move_view(int keycode, t_var *ui)
{
	if (keycode == KEY_UP)
		ui->f->i_origin -= (ui->f->max_r / 2) * 0.1;
	else if (keycode == KEY_DOWN)
		ui->f->i_origin += (ui->f->max_r / 2) * 0.1;
	else if (keycode == KEY_RIGHT)
		ui->f->r_origin += (ui->f->max_r / 2) * 0.1;
	else if (keycode == KEY_LEFT)
		ui->f->r_origin -= (ui->f->max_r / 2) * 0.1;
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}

void	reset_view(t_var *ui)
{
	ui->f->max_r = 2.5;
	ui->f->min_r = -2.5;
	ui->f->max_i = 1.25;
	ui->f->min_i = -1.25;
	ui->f->max_it = M_I;
	ui->f->r_origin = 0.0;
	ui->f->i_origin = 0.0;
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}

void	change_max_it(t_var *ui, int keycode)
{
	if (keycode == KEY_PLUS)
	{
		if (ui->f->max_it < 10)
			ui->f->max_it += 1;
		else
			ui->f->max_it += 10;
	}
	if (keycode == KEY_MINUS)
	{
		if (ui->f->max_it == 1)
		{
			write(1, "Max_it < 0 produces undef. behaviour and will therefore"\
				"not be shown.\n", 70);
		}
		else if (ui->f->max_it <= 10 && ui->f->max_it > 0)
			ui->f->max_it -= 1;
		else
			ui->f->max_it -= 10;
	}
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}
