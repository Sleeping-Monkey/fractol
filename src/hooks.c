/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:25:44 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:12:51 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define T_INC 10
#define R_INC 10

int		key_hook(int k, t_mlx *win)
{
	if (!win)
		return (1);
	k == KEY_ESC ? finish(win) : 0;
	k == KEY_UP ? (win->translation.c.im -= T_INC) : 0;
	k == KEY_DOWN ? (win->translation.c.im += T_INC) : 0;
	k == KEY_RIGHT ? (win->translation.c.re += T_INC) : 0;
	k == KEY_LEFT ? (win->translation.c.re -= T_INC) : 0;
	k == KEY_1 ? (win->spec = GRAY) : 0;
	k == KEY_2 ? (win->spec = PSY) : 0;
	k == KEY_3 ? (win->spec = OTHER) : 0;
	draw(win);
	return (1);
}

int		mouse_hook(int button, int x, int y, t_mlx *win)
{
	(void)x;
	(void)y;
	if (!win)
		return (1);
	if (button == 2)
		reset_view(win);
	else if (button == 4 || button == 5)
	{
		win->zoom_left += button == 4 ? -1 : 1;
		win->zoom_right += button == 4 ? -1 : 1;
		draw(win);
	}
	return (1);
}

int		mouse_move(int x, int y, t_mlx *win)
{
	if (win->type == JULIA)
	{
		win->pos_mouse.c = set_cmpl(x, y);
		draw(win);
	}
	return (1);
}
