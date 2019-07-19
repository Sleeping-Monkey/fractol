/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:23:13 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:06:19 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	parse_type(char *type, t_mlx *win)
{
	if (!ft_strcmp("mandelbrot", type))
		win->type = MANDEL;
	else if (!ft_strcmp("julia", type))
		win->type = JULIA;
	else if (!ft_strcmp("fractal", type))
		win->type = FRACTAL;
	else
		return (0);
	return (1);
}

static void	init_hooks(t_mlx *win)
{
	mlx_hook(win->win, 2, 0, &key_hook, win);
	mlx_mouse_hook(win->win, &mouse_hook, win);
	mlx_hook(win->win, 6, 0, &mouse_move, win);
	mlx_hook(win->win, 17, 0, &finish, win);
}

void		start(char *type)
{
	t_mlx	win;

	if (!parse_type(type, &win))
	{
		ft_putstr(USG_MSG);
		return ;
	}
	win.mlx = mlx_init();
	win.size_x = WIN_X;
	win.size_y = WIN_Y;
	win.win = mlx_new_window(win.mlx, win.size_x, win.size_y, "Hello!");
	init_hooks(&win);
	win.img.size_x = win.size_x;
	win.img.size_y = win.size_y;
	win.img.img = mlx_new_image(win.mlx, win.img.size_x, win.img.size_y);
	win.img.pic = (int *)mlx_get_data_addr(win.img.img,
						&win.img.bpp, &win.img.size_line, &win.img.endian);
	win.translation.c = set_cmpl(0, 0);
	win.pos_mouse.c = set_cmpl(win.size_x / 2.0, win.size_y / 2.0);
	win.zoom_left = 0;
	win.zoom_right = 0;
	win.spec = GRAY;
	draw(&win);
	mlx_loop(win.mlx);
}
