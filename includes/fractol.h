/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:35:02 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/18 11:14:22 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>

# include "mlx.h"
# include "libft.h"
# include "cmpl.h"
# include "cl.h"

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define WIN_X	2000
# define WIN_Y	1300
# define USG_MSG	"./fractol [mandelbrot \\ julia \\ fractal]\n"

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;
# define COLOR(r, g, b)((t_color){r, g, b})

typedef struct	s_point
{
	t_cmpl	c;
	t_color color;
}				t_point;


typedef	struct	s_img
{
	void	*img;
	int		*pic;
	int		bpp;
	int		size_y;
	int		size_x;
	int		size_line;
	int		endian;
}				t_img;

typedef enum	e_type
{
	MANDEL = 1,
	JULIA = 2,
	FRACTAL = 3
}				t_type;

typedef enum	e_spec
{
	GRAY = 1,
	PSY = 2,
	OTHER = 3
}				t_spec;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	unsigned	size_x;
	unsigned	size_y;
	t_type		type;
	t_spec		spec;
	t_img		img;
	t_point		translation;
	t_point		pos_mouse;
	cl_int		zoom_left;
	cl_int		zoom_right;
}				t_mlx;

void			start(char *type);

int				key_hook(int k, t_mlx *win);
int				mouse_hook(int button, int x, int y, t_mlx *win);
int				mouse_move(int x, int y, t_mlx *win);

void			set_point(t_point *pos, t_img *img);
void			set_img(t_mlx *win);
void			reset_view(t_mlx *win);
void			draw(t_mlx *win);

void			set_color(t_mlx *win, cl_int *n, size_t lenth);

void			mandel(t_mlx *win);
void			julia(t_mlx *win);
void			fractal(t_mlx *win);

int				finish(t_mlx *win);
void			err_finish(t_mlx *win, t_cl **cl, cl_mem *mem);

void			init_cl(t_mlx *win, cl_int *n, size_t size);

#endif
