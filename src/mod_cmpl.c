/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cmpl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:22:00 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/09 21:23:29 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmpl.h"

double	mod_cmpl(t_cmpl a)
{
	return (sqrt(a.re * a.re + a.im * a.im));
}
