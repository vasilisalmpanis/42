/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:33:25 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/18 12:06:08 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include "key_macros.h"

# define WIDTH 900
# define M_I 50
# define SHIFT_RATE 0.001

typedef struct s_complex
{
	double		min_r;
	int			shift;
	double		max_r;
	double		min_i;
	double		max_i;
	double 		shift_rate;
	double		r_origin;
	double		i_origin;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	double		x;
	double		y;
	double		temp;
	int			width;
	int			height;
	int			max_it;
	int			iter;
	int			bpp;
	int			size_line;
	int			endian;
	int			colours[M_I + 1];
	int			color;
	int			(*calc_color)(int iter);
}	t_complex;

typedef struct s_var
{
	void		(*set)(t_complex *f);
	t_complex	*f;
}	t_var;

void		draw_mandelbrot(t_complex *f);
t_var		*init_fractol(char *title, void *set);
void		mandlel_calc_c(t_complex *f);
void		mandel_calc_z(t_complex *f);
void		my_put_pixel(t_complex *f, int color);
void		no_parameters(void);
int			handle_mouse(int button, int x, int y, t_var *ui);
int			calc_color(int iter);
int			polynomial(int iter);
int			basic(int iter);
int			set_color(int t, int r, int g, int b);
int			keyboard_input(int keycode, t_var *ui);
void		change_max_it(t_var *ui, int keycode);
void		draw_window(t_var *ui);
void		print_lines(t_complex *f);
void		reset_view(t_var *ui);
void		change_colour(t_var *ui, int keycode);
int			ft_end(t_var *ui);
void		move_view(int keycode, t_var *ui);
void		draw_bs(t_complex *f);
void		bs_calc_c(t_complex *f);
void		bs_calc_z(t_complex *f);
void		draw_julia(t_complex *f);
void		julia_calc_z(t_complex *f);
void		julia_calc_start(t_complex *f);
void		julia_change_c(int x, int y, t_var *ui);
void		change_set(t_var *ui, int keycode);
void		shift_mode(t_var *ui, int keycode);
int			handle_no_events(t_var	*ui);
void		change_shift_rate(t_var *ui, int keycode);
void		key_5(t_var *ui);

#endif