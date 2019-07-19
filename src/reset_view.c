/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:39:24 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:07:05 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_view(t_mlx *win)
{
	win->zoom_left = 0;
	win->zoom_right = 0;
	win->translation.c = set_cmpl(0, 0);
	draw(win);
}
