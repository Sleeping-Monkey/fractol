/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:19:27 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/12 11:54:35 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_img(t_mlx *win, t_point *pos)
{
	if (win->type == MANDEL)
		mandel(win, pos);
	else if (win->type == JULIA)
		julia(win, pos);
}