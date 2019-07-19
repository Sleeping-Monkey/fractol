/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:54:23 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:08:55 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl.h"
#include "fractol.h"

void	create_type_cl(t_mlx *win, t_cl **cl)
{
	if (win->type == JULIA)
	{
		if (!(*cl = create_cl("./src/julia.cl", "julia")))
			err_finish(win, NULL, NULL);
	}
	else if (win->type == MANDEL)
	{
		if (!(*cl = create_cl("./src/mandel.cl", "mandel")))
			err_finish(win, NULL, NULL);
	}
	else
	{
		if (!(*cl = create_cl("./src/fractal.cl", "fractal")))
			err_finish(win, NULL, NULL);
	}
}

void	init_cl(t_mlx *win, cl_int *n, size_t size)
{
	t_cl	*cl;
	cl_mem	memobj;

	create_type_cl(win, &cl);
	if (!(memobj = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, \
	size * sizeof(cl_int), NULL, &cl->ret)))
		err_finish(win, &cl, NULL);
	if ((cl->ret = clEnqueueWriteBuffer(cl->command_queue, memobj, CL_TRUE, \
	0, size * sizeof(cl_int), n, 0, NULL, NULL)))
		err_finish(win, &cl, &memobj);
	if ((cl->ret = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), \
	(void *)&memobj)))
		err_finish(win, &cl, &memobj);
	if ((cl->ret = clEnqueueNDRangeKernel(cl->command_queue, cl->kernel, 1, \
	NULL, &size, NULL, 0, NULL, NULL)))
		err_finish(win, &cl, &memobj);
	if ((cl->ret = clEnqueueReadBuffer(cl->command_queue, memobj, CL_TRUE, 0, \
	size * sizeof(cl_int), n, 0, NULL, NULL)))
		err_finish(win, &cl, &memobj);
	clReleaseMemObject(memobj);
	del_cl(&cl);
}
