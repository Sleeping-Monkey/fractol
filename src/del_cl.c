/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:02:03 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/19 11:09:37 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl.h"

t_cl	*del_cl(t_cl **cl)
{
	if (!cl || !*cl)
		return (NULL);
	clFlush((*cl)->command_queue);
	clFinish((*cl)->command_queue);
	clReleaseKernel((*cl)->kernel);
	clReleaseProgram((*cl)->program);
	clReleaseCommandQueue((*cl)->command_queue);
	clReleaseContext((*cl)->context);
	clReleaseDevice((*cl)->device_id);
	clUnloadPlatformCompiler((*cl)->platform_id);
	free(*cl);
	*cl = NULL;
	return (NULL);
}
