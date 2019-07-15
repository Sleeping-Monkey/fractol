/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:23:13 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/11 14:08:36 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	parse_type(char *type, t_mlx *win)
{
	if (!ft_strcmp("mandelbrot", type))
		win->type = MANDEL;
	else if (!ft_strcmp("julia", type))
		win->type = JULIA;
	else
		return (0);
	return (1);
}

void		start(char *type)
{
	t_mlx	win;
	t_point	pos;

	if (!parse_type(type, &win))
	{
		ft_putstr(USG_MSG);
		return ;
	}
	win.mlx = mlx_init();
	win.size_x = WIN_X;
	win.size_y = WIN_Y;
	win.win = mlx_new_window(win.mlx, win.size_x, win.size_y, "Hello!");
	mlx_key_hook(win.win, &key_hook, &win);
	mlx_mouse_hook(win.win, &mouse_hook, &win);
	mlx_hook(win.win, 17, 0, &finish, &win);
//	mlx_loop_hook(win.win, &key_hook, &win);
	win.img.size_x = win.size_x;
	win.img.size_y = win.size_y;
	win.img.img = mlx_new_image(win.mlx, win.img.size_y, win.img.size_x);
	win.img.pic = (int *)mlx_get_data_addr(win.img.img,
						&win.img.bpp, &win.img.size_line, &win.img.endian);
	pos.c = set_cmpl(WIN_X / 2, WIN_Y / 2);
//	set_img(&win, &pos);
	draw(&win, &pos);
//	reset_view(&win);
//	draw(&win);
	mlx_loop(win.mlx);
}