/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_d_maj_tool2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:40:26 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:40:32 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_long_width_prec(t_flags *flags, int *tab, long int c)
{
	int size;

	size = (c >= 0) ? ft_longnbrlen(c) : ft_longnbrlen(c) + 1;
	if (flags->width < size && flags->precision < ft_longnbrlen(c))
		print_long_no_size(flags, tab, c);
	else if (flags->width > size && flags->precision < ft_longnbrlen(c))
		print_long_width_no_prec(flags, tab, c);
	else if (flags->width < size && flags->precision > ft_longnbrlen(c))
		print_long_prec_no_width(flags, tab, c);
	else
		print_long_width_prec(flags, tab, c);
}

void	print_long_no_flags(t_flags *flags, int *tab, long int c)
{
	if (!flags->width && !flags->precision)
		print_long_no_size(flags, tab, c);
	else if (flags->width && !flags->precision)
		print_long_width_no_prec(flags, tab, c);
	else if (!flags->width && flags->precision)
		print_long_prec_no_width(flags, tab, c);
	else
		check_long_width_prec(flags, tab, c);
}

void	print_long_flag_zero(t_flags *flags, int *tab, long int c)
{
	int size;

	size = (c >= 0) ? ft_longnbrlen(c) : ft_longnbrlen(c) + 1;
	if (flags->width && flags->width > size && !flags->precision)
	{
		c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		ft_filler('0', flags->width - size);
		ft_putlongnbr(c);
		tab[1] += flags->width;
	}
	else
		print_long_no_flags(flags, tab, c);
}

void	print_long_flag_space(t_flags *flags, int *tab, long int c)
{
	int size;

	size = (c >= 0) ? ft_longnbrlen(c) : ft_longnbrlen(c) + 1;
	if (c >= 0 && ((flags->width <= size && !flags->precision) ||
		(flags->precision && (!flags->width || flags->width <= size)) ||
		(flags->width == flags->precision)))
	{
		ft_putchar(' ');
		tab[1] += 1;
		print_long_no_flags(flags, tab, c);
	}
	else
		print_long_no_flags(flags, tab, c);
}

void	print_long_flag_min(t_flags *flags, int *tab, long int c, va_list list)
{
	int size;

	size = (c >= 0) ? ft_longnbrlen(c) : ft_longnbrlen(c) + 1;
	if (flags->width && flags->width > size && ((!flags->precision ||
		flags->precision <= ft_longnbrlen(c)) ||
		(flags->precision > ft_longnbrlen(c) &&
		flags->precision < flags->width)))
		print_long_width_prec_rev(flags, tab, c);
	else
	{
		flags->o_min = 0;
		arg_is_long_int_flags(flags, list, tab, c);
	}
}
