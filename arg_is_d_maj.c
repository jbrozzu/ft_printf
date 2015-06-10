/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_d_maj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:40:00 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:40:04 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_is_long_int_flags(t_flags *flags, va_list list,
	int *tab, long int c)
{
	if (flags->o_min)
		print_long_flag_min(flags, tab, c, list);
	else if (flags->o_zero)
		print_long_flag_zero(flags, tab, c);
	else if (flags->o_space)
		print_long_flag_space(flags, tab, c);
	else
		print_long_no_flags(flags, tab, c);
}

void	get_long_int(t_flags *flags, va_list list, int *tab)
{
	long long int c;

	if (flags->modif1 == 'j')
		c = (intmax_t)va_arg(list, intmax_t);
	else if (flags->modif1 == 'z')
		c = (size_t)va_arg(list, size_t);
	else if (flags->modif1 == 'l' && flags->modif2 == '\0')
		c = (long)va_arg(list, long int);
	else
		c = va_arg(list, unsigned long long int);
	if (c < -9223372036854775807)
	{
		ft_putstr("-9223372036854775808");
		tab[1] += 20;
		return ;
	}
	arg_is_long_int_flags(flags, list, tab, c);
}
