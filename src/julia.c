/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:59 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:09:04 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "cl.h"

static void	set_first_params(cl_int *n, t_mlx *win)
{
	n[0] = 8;
	n[1] = win->size_x;
	n[2] = win->size_y;
	n[3] = win->pos_mouse.c.re;
	n[4] = win->pos_mouse.c.im;
	n[5] = win->zoom_left;
	n[6] = win->zoom_right;
	n[7] = win->translation.c.re;
	n[8] = win->translation.c.im;
}

void		julia(t_mlx *win)
{
	size_t	lenth;
	cl_int	*n;

	errno = 0;
	lenth = win->size_y * win->size_x + 9;
	if (!(n = (cl_int *)malloc(sizeof(cl_int) * lenth)))
	{
		perror("fractol");
		finish(win);
	}
	ft_bzero((void *)n, sizeof(cl_int) * lenth);
	set_first_params(n, win);
	init_cl(win, n, lenth);
	set_color(win, n, lenth);
	free(n);
}
