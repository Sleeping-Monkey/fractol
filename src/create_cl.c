/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:06:13 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/15 10:57:13 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl.h"
#include <stdio.h>

t_cl	*create_cl(char *file_name, char *func_name)
{
	t_cl	*new_cl;
	char	*buff;
	size_t	pos;
	int		fd;

	if (!(new_cl = (t_cl *)malloc(sizeof(t_cl))))
		return (NULL);
	printf("create_cl 1\n");
	/* получить доступные платформы */
	if ((new_cl->ret = clGetPlatformIDs(1, &new_cl->platform_id, \
	&new_cl->ret_num_platforms)))
		return (del_cl(&new_cl));

	printf("create_cl 2\n");
	/* получить доступные устройства */
	if ((new_cl->ret = clGetDeviceIDs(new_cl->platform_id, \
	CL_DEVICE_TYPE_DEFAULT, 1, &new_cl->device_id, &new_cl->ret_num_devices)))
		return (del_cl(&new_cl));
	printf("create_cl 3\n");
	/* создать контекст */
	if (!(new_cl->context = clCreateContext(NULL, 1, &new_cl->device_id, \
	NULL, NULL, &new_cl->ret)))
		return (del_cl(&new_cl));
	printf("create_cl 3\n");
	/* создаем команду */
	if (!(new_cl->command_queue = clCreateCommandQueue(new_cl->context, \
	new_cl->device_id, 0, &new_cl->ret)))
		return (del_cl(&new_cl));
	printf("create_cl 4\n");

	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (del_cl(&new_cl));
	printf("create_cl 4.5\n");	
	fd = open(file_name, O_RDONLY);
	if (fd < 0) {
		exit(1);
	}
	pos = read(fd, buff, BUFF_SIZE);
	close(fd);
	printf("create_cl 5\n");
	/* создать бинарник из кода программы */
	if (!(new_cl->program = clCreateProgramWithSource(new_cl->context, 1, \
	(const char **)&buff, (const size_t *)&pos, &new_cl->ret)))
		return (del_cl(&new_cl));
	free(buff);
	printf("create_cl 6\n");
	/* скомпилировать программу */
	if ((new_cl->ret = clBuildProgram(new_cl->program, 1, &new_cl->device_id, \
	NULL, NULL, NULL)) != CL_SUCCESS)
	{
		printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d - %d\n", CL_SUCCESS, CL_INVALID_PROGRAM, CL_INVALID_VALUE, CL_INVALID_DEVICE, CL_INVALID_BINARY, CL_INVALID_BUILD_OPTIONS, CL_INVALID_OPERATION, \
		CL_COMPILER_NOT_AVAILABLE, CL_DEVICE_COMPILER_AVAILABLE, CL_BUILD_PROGRAM_FAILURE, CL_INVALID_OPERATION, CL_OUT_OF_HOST_MEMORY, new_cl->ret);
		clGetProgramBuildInfo(new_cl->program, new_cl->device_id, CL_PROGRAM_BUILD_LOG, 2048*sizeof(char), buff, &pos);
      printf("%s", buff);
      clGetProgramBuildInfo(new_cl->program, new_cl->device_id, CL_PROGRAM_BUILD_STATUS, 2048*sizeof(char), buff, &pos);
      printf("%s", buff);
      clGetProgramBuildInfo(new_cl->program, new_cl->device_id, CL_PROGRAM_BUILD_OPTIONS, 2048*sizeof(char), buff, &pos);
      printf("%s", buff);
		return (del_cl(&new_cl));
	}
	printf("create_cl 7\n");
	/* создать кернел */
	if (!(new_cl->kernel = clCreateKernel(new_cl->program, func_name, &new_cl->ret)))
		return (del_cl(&new_cl));
	printf("create_cl 8\n");
	return (new_cl);
}