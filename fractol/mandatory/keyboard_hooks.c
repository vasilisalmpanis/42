/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:04:30 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/16 12:51:47 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_input(int keycode, t_complex *f)
{
	// printf("%d\n", keycode);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		change_max_it(f, keycode);
	else if (keycode == KEY_R)
		reset_view(f);
	else if (keycode == KEY_BLUE || keycode == KEY_GREEN)
		change_colour(f, keycode);
	else if (keycode == KEY_ESCAPE)
		ft_end(f);
	return (1);
}

void	reset_view(t_complex *f)
{
	f->max_it = M_I;
	f->max_r = 2.0;
	f->min_r = -f->max_r;
	f->max_i = 1.0;
	f->min_i = -1.0;
	f->r_origin = 0.0;
	f->i_origin = 0.0;
	mlx_clear_window(f->mlx, f->win);
	draw_window(f);
}

void	change_max_it(t_complex *f, int keycode)
{
	if (keycode == KEY_PLUS)
	{
		if (f->max_it < 10)
			f->max_it += 1;
		else
			f->max_it += 10;
	}
	if (keycode == KEY_MINUS)
	{
		if (f->max_it == 1)
		{
			write(1, "Max_it < 0 produces undef. behaviour and will therefore"\
				"not be shown.\n", 70);
		}
		else if (f->max_it <= 10 && f->max_it > 0)
			f->max_it -= 1;
		else
			f->max_it -= 10;
	}
	mlx_clear_window(f->mlx, f->win);
	draw_window(f);
}
