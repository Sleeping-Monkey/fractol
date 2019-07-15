/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:02:03 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/15 11:00:39 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl.h"

t_cl	*del_cl(t_cl **cl)
{
//	(void)cl;
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
//	free((*cl)->platform_id);
	free(*cl);
	*cl = NULL;
	return (NULL);
}