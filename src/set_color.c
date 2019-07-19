/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:27:28 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:06:37 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	get_color(t_mlx *win, cl_int n)
{
	if (win->spec == GRAY)
		return (COLOR(n, n, n));
	if (win->spec == PSY)
		return (COLOR(n * n, n * n * n, n));
	return (COLOR(150 - n, 100 + n * 2, n));
}

void			set_color(t_mlx *win, cl_int *n, size_t lenth)
{
	size_t	i;
	t_point	p;

	i = n[0];
	while (++i < lenth)
	{
		p.c = set_cmpl((i - n[0] - 1) % win->size_x, (i - n[0] - 1) / n[1]);
		p.color = get_color(win, n[i]);
		set_point(&p, &win->img);
	}
}
