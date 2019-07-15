/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmpl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:16:44 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/10 12:10:16 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmpl.h"

t_cmpl	add_cmpl(t_cmpl a, t_cmpl b)
{
	t_cmpl res;

	res.re = a.re + b.re;
	res.im = a.im + b.im;
	return (res);
}
