/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:06:02 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/12 12:04:45 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr(USG_MSG);
		return (0);
	}
	start(argv[1]);
	return (0);
}