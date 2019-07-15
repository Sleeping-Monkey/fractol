/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:22:59 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/11 13:13:48 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_win(t_mlx *win, t_color *color)
{
	size_t	i;
	int		c;

	i = win->img.size_x * win->img.size_y;
	c = (int)((unsigned)((color->r << 8u) + color->g) << 8u) + color->b;
	while (i--)
		win->img.pic[i] = c;
}

void	draw(t_mlx *win, t_point *pos)
{
	fill_win(win, &COLOR(255, 255, 255));
	set_img(win, pos);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
}
