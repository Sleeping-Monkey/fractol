/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_cmpl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:18:26 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/09 21:21:37 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmpl.h"

t_cmpl	mul_cmpl(t_cmpl a, t_cmpl b)
{
	t_cmpl	res;

	res.re = a.re * b.re - a.im * b.im;
	res.im = a.re * b.im + a.im * b.re;
	return (res);
}
