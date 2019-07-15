/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:45:59 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/12 13:09:38 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	count_n(t_cmpl z, t_cmpl c)
{
	int n;

	n = 0;
    while (n < 255 && mod_cmpl(z) <= 2)
	{
		z = add_cmpl(mul_cmpl(z, z), c);
		n++;
    }
    return (n);
}


void		julia(t_mlx *win, t_point *pos)
{
	t_point		z0;
	t_point		z;
	int			y;
	int			x;
	int			n;

//printf("julia: \n");
	z0.c = set_cmpl(pos->c.re / win->size_x, pos->c.im / win->size_y);
	y = -1;
	while (++y < (int)win->size_y)
	{
		x = -1;
		while (++x < (int)win->size_x)
		{
			z.c = set_cmpl(-2.0L + 4.0L * (x / (double)win->size_x), \
			-2.0L + 4.0L * (y / (double)win->size_y));
			n = count_n(z.c, z0.c);
//			printf("(%Lf, %Lf) - %d\n", z.c.re, z.c.im, n);
			z.color = COLOR(n, n * n * n, n * n);
			z.c.re = x;
			z.c.im = y;
			set_point(&z, &win->img);
		}
	}
//printf("finish julia\n");
}