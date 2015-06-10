/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:39:38 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:39:49 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		max_unsigned_long(t_flags *flags)
{
	int size;

	size = 22;
	if (flags->width > size + flags->precision)
		ft_filler(' ', flags->width - flags->precision);
	if (flags->precision)
	{
		ft_filler('0', flags->precision - size);
		size += flags->precision - size;
	}
	ft_putstr("1777777777777777777777");
	if (flags->width > flags->precision + size)
		size += flags->width - size;
	return (size);
}

int		max_long(t_flags *flags)
{
	int size;

	size = 11;
	if (flags->width > size + flags->precision)
		ft_filler(' ', flags->width - flags->precision);
	if (flags->precision)
	{
		ft_filler('0', flags->precision - size);
		size += flags->precision - size;
	}
	ft_putstr("37777777777");
	if (flags->width > flags->precision + size)
		size += flags->width - size;
	return (size);
}

int		max_unsigned_octal_long(t_flags *flags)
{
	int size;

	size = 22;
	if (flags->width > size + flags->precision)
		ft_filler(' ', flags->width - flags->precision);
	if (flags->precision)
	{
		ft_filler('0', flags->precision - size);
		size += flags->precision - size;
	}
	ft_putstr("1000000000000000000000");
	if (flags->width > flags->precision + size)
		size += flags->width - size;
	return (size);
}

int		limit_max(t_flags *flags, unsigned long long nb)
{
	int size;

	size = 0;
	if ((flags->type == 'O' || flags->modif1 == 'l' || flags->modif1 == 'j' \
		|| flags->modif1 == 'z') && nb >= ULONG_MAX)
		size = max_unsigned_long(flags);
	else if ((flags->type == 'o' && flags->modif1 == '\0') && nb >= LONG_MAX)
		size = max_long(flags);
	else
		size = max_unsigned_octal_long(flags);
	return (size);
}
