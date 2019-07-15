/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:35:02 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/15 15:03:44 by ssheba           ###   ########.fr       */
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

# define KEY_ESC 53
# define WIN_X	1000
# define WIN_Y	1300
# define USG_MSG	"./fractol [mandelbrot \\ julia]\n"

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
	JULIA = 2
}				t_type;	

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	unsigned	size_x;
	unsigned	size_y;
	t_type		type;
	t_img		img;
}				t_mlx;

void			start(char *type);

int				key_hook(int k, t_mlx *win);
int				mouse_hook(int button, int x, int y, t_mlx *win);

void			set_point(t_point *pos, t_img *img);
void			set_img(t_mlx *win, t_point *pos);
void			draw(t_mlx *win, t_point *pos);

void			mandel(t_mlx *win, t_point *pos);
void			julia(t_mlx *win, t_point *pos);

int				finish(t_mlx *win);

#endif
