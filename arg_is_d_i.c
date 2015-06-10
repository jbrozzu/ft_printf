/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:30:53 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:30:57 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_min(t_flags *flags, int *tab, int c, va_list list)
{
	int size;

	size = (c >= 0) ? ft_nbrlen(c) : ft_nbrlen(c) + 1;
	if (flags->width && flags->width > size && ((!flags->precision ||
		flags->precision <= ft_nbrlen(c)) || (flags->precision > ft_nbrlen(c) &&
		flags->precision < flags->width)))
		print_width_prec_rev(flags, tab, c);
	else
	{
		flags->o_min = 0;
		arg_is_int_flags(flags, list, tab, c);
	}
}

void	cast_int(int *c, va_list list, t_flags *flags)
{
	if (flags->modif1 == 'h' && flags->modif2 == 'h')
		*c = (signed char)va_arg(list, int);
	else if (flags->modif1 == 'h' && flags->modif2 == '\0')
		*c = (short)va_arg(list, int);
	else
		*c = va_arg(list, int);
}

void	arg_is_int_flags(t_flags *flags, va_list list, int *tab, int c)
{
	if (flags->o_min)
		print_flag_min(flags, tab, c, list);
	else if (flags->o_zero)
		print_flag_zero(flags, tab, c);
	else if (flags->o_space)
		print_flag_space(flags, tab, c);
	else
		print_no_flags(flags, tab, c);
}

void	get_int(t_flags *flags, va_list list, int *tab)
{
	int c;

	cast_int(&c, list, flags);
	arg_is_int_flags(flags, list, tab, c);
}

void	arg_is_int(t_flags *flags, va_list list, int *tab)
{
	if (flags->modif1 == 'l' || flags->modif1 == 'j' ||
		flags->modif1 == 'z' || flags->type == 'D')
		get_long_int(flags, list, tab);
	else
		get_int(flags, list, tab);
}
