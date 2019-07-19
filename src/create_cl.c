/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:06:13 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:13:14 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl.h"
#include <stdio.h>

int		before_read_file(t_cl *new_cl)
{
	if ((new_cl->ret = clGetPlatformIDs(1, &new_cl->platform_id, \
	&new_cl->ret_num_platforms)))
		return (0);
	if ((new_cl->ret = clGetDeviceIDs(new_cl->platform_id, \
	CL_DEVICE_TYPE_GPU, 1, &new_cl->device_id, &new_cl->ret_num_devices)))
		return (0);
	if (!(new_cl->context = clCreateContext(NULL, 1, &new_cl->device_id, \
	NULL, NULL, &new_cl->ret)))
		return (0);
	if (!(new_cl->command_queue = clCreateCommandQueue(new_cl->context, \
	new_cl->device_id, 0, &new_cl->ret)))
		return (0);
	return (1);
}

int		read_file(t_cl *new_cl, char *file_name)
{
	char	*buff;
	size_t	pos;
	int		fd;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	pos = read(fd, buff, BUFF_SIZE);
	close(fd);
	if (!(new_cl->program = clCreateProgramWithSource(new_cl->context, 1, \
	(const char **)&buff, (const size_t *)&pos, &new_cl->ret)))
	{
		free(buff);
		return (0);
	}
	free(buff);
	return (1);
}

t_cl	*create_cl(char *file_name, char *func_name)
{
	t_cl	*new_cl;

	if (!(new_cl = (t_cl *)malloc(sizeof(t_cl))))
		return (NULL);
	if (!before_read_file(new_cl))
		return (del_cl(&new_cl));
	if (!read_file(new_cl, file_name))
		return (del_cl(&new_cl));
	if ((new_cl->ret = clBuildProgram(new_cl->program, 1, &new_cl->device_id, \
	NULL, NULL, NULL)) != CL_SUCCESS)
		return (del_cl(&new_cl));
	if (!(new_cl->kernel = clCreateKernel(new_cl->program, func_name, \
	&new_cl->ret)))
		return (del_cl(&new_cl));
	return (new_cl);
}
