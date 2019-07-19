/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:27:26 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/17 14:52:04 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		finish(t_mlx *win)
{
	mlx_destroy_image(win->mlx, win->img.img);
	mlx_destroy_window(win->mlx, win->win);
	free(win->mlx);
	exit(0);
}

void	err_finish(t_mlx *win, t_cl **cl, cl_mem *mem)
{
	perror("fractol");
	if (cl)
		del_cl(cl);
	if (mem)
		clReleaseMemObject(*mem);
	finish(win);
}
