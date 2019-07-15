/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:31:35 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/15 10:55:51 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_H
# define CL_H

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define BUFF_SIZE	100000

typedef struct	s_cl
{
	int					ret;
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;
}				t_cl;

t_cl					*create_cl(char *file_name, char *func_name);
t_cl					*del_cl(t_cl **cl);


#endif