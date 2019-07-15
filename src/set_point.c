/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:36:21 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/10 17:52:21 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_point(t_point *pos, t_img *img)
{
	unsigned	color;

	color = (((pos->color.r << 8) + pos->color.g) << 8) + pos->color.b;
	if (pos->c.re > 0 && pos->c.re < img->size_x && pos->c.im > 0 && \
	pos->c.im < img->size_y)
		img->pic[(size_t)(img->size_x * (int)(pos->c.im) + \
		(int)(pos->c.re))] = color;
}
