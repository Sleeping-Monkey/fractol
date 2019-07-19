/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:19:27 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:06:46 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_img(t_mlx *win)
{
	if (win->type == MANDEL)
		mandel(win);
	else if (win->type == JULIA)
		julia(win);
	else if (win->type == FRACTAL)
		fractal(win);
}
