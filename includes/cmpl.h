/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:47:58 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/11 10:55:39 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMPL_H
# define CMPL_H

#include <math.h>

typedef struct	s_cmpl
{
	long double	re;
	long double	im;
}				t_cmpl;

t_cmpl			set_cmpl(long double re, long double im);
t_cmpl			add_cmpl(t_cmpl a, t_cmpl b);
t_cmpl			mul_cmpl(t_cmpl a, t_cmpl b);
double			mod_cmpl(t_cmpl a);

#endif