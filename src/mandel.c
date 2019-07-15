/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:53:29 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/15 14:47:42 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "cl.h"

void	mandel(t_mlx *win, t_point *pos)
{
	cl_mem	memobj;
	size_t	lenth;
	t_cl	*cl;
	cl_int	*n;
	t_point	p;
	size_t	i;

(void)pos;
printf("mandelbrot start\n");
	errno = 0;
	if (!(cl = create_cl("./src/mandel.cl", "mandel")))
	{
		printf("you lose!\n");
		finish(win);
	}
printf("mandelbrot 1\n");
	lenth = win->size_y * win->size_x + 5;
		/* создать буфер */
	memobj = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, lenth * sizeof(cl_int), NULL, &cl->ret);
printf("mandelbrot 2\n");
	if (!(n = (cl_int *)malloc(sizeof(cl_int) * lenth)))
	{
		perror("n:");
		printf("errno == %d\n", errno);
		finish(win);
	}
printf("mandelbrot malloc is ok\n");
	ft_bzero((void *)n, sizeof(cl_int) * lenth);
	n[0] = 4;
	n[1] = win->size_x;
	n[2] = win->size_y;
	n[3] = 0;
	n[4] = 0;
	/* записать данные в буфер */
	cl->ret = clEnqueueWriteBuffer(cl->command_queue, memobj, CL_TRUE, 0, lenth * sizeof(cl_int), n, 0, NULL, NULL);


	/* устанавливаем параметр */
	cl->ret = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), (void *)&memobj);

	/* выполнить кернел */
	cl->ret = clEnqueueNDRangeKernel(cl->command_queue, cl->kernel, 1, NULL, &lenth, NULL, 0, NULL, NULL);

	/* считать данные из буфера */
	cl->ret = clEnqueueReadBuffer(cl->command_queue, memobj, CL_TRUE, 0, lenth * sizeof(cl_int), n, 0, NULL, NULL);

	i = n[0];
	while (++i < lenth)
	{
		p.c = set_cmpl((i - n[0] - 1) % win->size_x, (i - n[0] - 1) / n[1]);
		p.color = COLOR(n[i] * n[i] * n[i], n[i] * n[i], n[i]);
//		printf("(%Lf, %Lf) - %d\n", p.c.re, p.c.im, n[i]);
		set_point(&p, &win->img);
	}
	clReleaseMemObject(memobj);
	free(n);
	del_cl(&cl);
	printf("mandelbrot finish\n");
/*	y = -win->size_y;
	(void)pos;
	while (++y < (int)win->size_y)
	{
		x = -win->size_x;
		while (++x < (int)win->size_x)
		{
			z0.c = set_cmpl(-1.7433419053321L - 0.00000000374L + x * \
			0.00000000374L * 2.0 / win->size_x, 0.0000907687489L - \
			0.00000000374L + y * 0.00000000374L * 2.0 / win->size_y);
			z.c = z0.c;
			n = 0;
			while (n < 255 && mod_cmpl(z.c) < 2)
			{
				z.c = add_cmpl(mul_cmpl(z.c, z.c), z0.c);
				n++;
			}
			z.color = COLOR(n * n * n, n * n, n);
			z.c.re = x;
			z.c.im = y;
			set_point(&z, &win->img);
		}
	}*/

}
