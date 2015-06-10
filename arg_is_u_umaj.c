/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_u_umaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:41:53 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:41:57 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_unsigned(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->modif1 == 'j')
		*c = (uintmax_t)va_arg(list, uintmax_t);
	else if (flags->modif1 == 'z')
		*c = (ssize_t)va_arg(list, ssize_t);
	else if (flags->modif1 == 'h' && flags->modif2 == 'h' && flags->type != 'U')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->modif1 == 'h')
		*c = (unsigned short)va_arg(list, int);
	else if (flags->modif1 == 'l' && flags->modif2 == '\0')
		*c = (unsigned long)va_arg(list, unsigned long int);
	else if ((flags->modif1 == 'l' && flags->modif2 == 'l') ||
		flags->type == 'U')
		*c = va_arg(list, unsigned long long int);
	else
		*c = (unsigned int)va_arg(list, unsigned int);
}

void	print_u_flag_min(t_flags *flags, unsigned long long int value, int *tab)
{
	int size;

	size = ft_lnbrlen(value);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision < size || flags->width > flags->precision))
	{
		if (flags->precision && flags->precision > size)
		{
			ft_filler('0', flags->precision - size);
			ft_putlnbr(value);
		}
		if (flags->precision && flags->precision > size)
			ft_filler(' ', flags->width - flags->precision);
		else
			ft_filler(' ', flags->width - size);
		tab[1] += flags->width;
	}
	else
		print_u_no_flags(flags, value, tab);
}

void	print_u_flag_zero(t_flags *flags, unsigned long long int value,
	int *tab)
{
	int size;

	size = ft_lnbrlen(value);
	if (flags->width && !flags->o_point && !flags->precision &&
		flags->width > size)
	{
		ft_filler('0', flags->width - size);
		ft_putlnbr(value);
		tab[1] += flags->width;
	}
	else
		print_u_no_flags(flags, value, tab);
}

void	get_unsigned_flag(t_flags *flags, unsigned long long int value,
	int *tab)
{
	if (flags->o_min)
		print_u_flag_min(flags, value, tab);
	else if (flags->o_zero)
		print_u_flag_zero(flags, value, tab);
	else
		print_u_no_flags(flags, value, tab);
}

void	arg_is_unsigned(t_flags *flags, va_list list, int *tab)
{
	unsigned long long int	value;

	cast_unsigned(&value, list, flags);
	get_unsigned_flag(flags, value, tab);
}
