/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:33:25 by valmpani          #+#    #+#             */
/*   Updated: 2023/07/16 13:39:04 by valmpani         ###   ########.fr       */
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

# define WIDTH 1600
# define M_I 50

typedef struct s_complex
{
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		range_r;
	double		range_i;
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

void	draw_set(t_complex *f);
void	init_fractol(t_complex *f, char *title);
void	mandlel_calc_c(t_complex *f);
void	mandel_calc_z(t_complex *f);
void	my_put_pixel(t_complex *f, int color);
void	no_parameters(void);
int		handle_mouse(int button, int x, int y, t_complex *f);
int		calc_color(int iter);
int		polynomial(int iter);
int		basic(int iter);
int		set_color(int t, int r, int g, int b);
int		keyboard_input(int keycode, t_complex *f);
void	change_max_it(t_complex *f, int keycode);
void	draw_window(t_complex *f);
void	print_lines(t_complex *f);
void	reset_view(t_complex *f);
void	change_colour(t_complex *f, int keycode);
int		ft_end(t_complex *f);

#endif