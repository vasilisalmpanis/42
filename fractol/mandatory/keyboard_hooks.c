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

/*
 * Function:  keyboard_input
 * --------------------
 * @keycode : Code of the key pressed
 * @ui : They ui struct
 * Executes the corresponding function according to key pressed
 */
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
	else if (keycode == KEY_SHIFT)
		shift_mode(ui, keycode);
	else if (keycode == KEY_4 || keycode == KEY_5)
		change_shift_rate(ui, keycode);
	return (1);
}

/*
 * Function:  change_set
 * --------------------
 * @keycode : Code of the key pressed
 * @ui : They ui struct
 * Changes the set and resets some values for default view and behaviour
 * 1 : Mandelbrot
 * 2 : Julia
 * 3 : Burning ships
 */
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
	{
		ui->set = draw_julia;
		ui->f->c_r = 0;
		ui->f->c_i = 0;
	}
	else if (keycode == KEY_3)
		ui->set = draw_bs;
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}

/*
 * Function:  move_view
 * --------------------
 * @keycode : Code of the key pressed
 * @ui : They ui struct
 * Moves the view up down left right depending on arrow key pressed
 */
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

/*
 * Function:  reset_view
 * --------------------
 * @ui : They ui struct
 * Resets the values to defaults so the set goes back to normal
 * Iterations are reset too.
 */
void	reset_view(t_var *ui)
{
	ui->f->max_r = 2.5;
	ui->f->min_r = -2.5;
	ui->f->max_i = 1.25;
	ui->f->min_i = -1.25;
	ui->f->max_it = M_I;
	ui->f->r_origin = 0.0;
	ui->f->i_origin = 0.0;
	ui->f->c_r = 0.0;
	ui->f->c_i = 0.0;
	ui->f->shift_rate = SHIFT_RATE;
	mlx_clear_window(ui->f->mlx, ui->f->win);
	draw_window(ui);
}

/*
 * Function:  change_max_it
 * --------------------
 * @keycode : Code of the key pressed
 * @ui : They ui struct
 * When + is pressed 10 iterations are added
 * When - is pressed 10 iterations are subtracted
 * When iterations are < 10 only 1 is subtracted
 * If iterations is 1 no values can be subtracted only added.
 */
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
