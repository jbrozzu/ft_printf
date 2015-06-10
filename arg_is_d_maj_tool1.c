/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_d_maj_tool1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:40:12 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:40:21 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_long_no_size(t_flags *flags, int *tab, long int c)
{
	if (c < 0 || (flags->o_plus && c >= 0))
		tab[1] += 1;
	if (flags->o_plus && c >= 0)
		ft_putchar('+');
	ft_putlongnbr(c);
	tab[1] += ft_longnbrlen(c);
}

void	print_long_width_no_prec(t_flags *flags, int *tab, long int c)
{
	int size;

	size = (c >= 0) ? ft_longnbrlen(c) : ft_longnbrlen(c) + 1;
	if (flags->o_plus && c >= 0)
		size += 1;
	if (flags->width > size)
	{
		ft_filler(' ', flags->width - size);
		if (flags->o_plus && c >= 0)
			ft_putchar('+');
		ft_putlongnbr(c);
		tab[1] += flags->width;
	}
	else
		print_long_no_size(flags, tab, c);
}

void	print_long_width_prec_rev(t_flags *flags, int *tab, long int c)
{
	int i;
	int size;

	i = 0;
	if (c < 0)
	{
		size = ft_longnbrlen(c) + 1;
		i += 1;
		c = -c;
		ft_putchar('-');
	}
	else
		size = ft_longnbrlen(c);
	if (flags->precision && flags->precision > ft_longnbrlen(c))
		ft_filler('0', flags->precision - ft_longnbrlen(c));
	ft_putlongnbr(c);
	if (flags->precision && flags->precision > ft_longnbrlen(c))
		ft_filler(' ', flags->width - (flags->precision + i));
	else
		ft_filler(' ', flags->width - size);
	tab[1] += flags->width;
}

void	print_long_prec_no_width(t_flags *flags, int *tab, long int c)
{
	if (flags->precision > ft_longnbrlen(c))
	{
		if (flags->o_plus && c >= 0)
		{
			ft_putchar('+');
			tab[1] += 1;
		}
		c < 0 ? (c = -c, ft_putchar('-'), tab[1] += 1) : (c += 0);
		ft_filler('0', flags->precision - ft_longnbrlen(c));
		ft_putlongnbr(c);
		tab[1] += flags->precision;
	}
	else
		print_long_no_size(flags, tab, c);
}

void	print_long_width_prec(t_flags *flags, int *tab, long int c)
{
	int i;

	i = 0;
	if (c < 0 || (flags->o_plus && c >= 0))
		i += 1;
	if (flags->precision >= flags->width)
		print_long_prec_no_width(flags, tab, c);
	else
	{
		ft_filler(' ', flags->width - (flags->precision + i));
		if (flags->o_plus && c >= 0)
			ft_putchar('+');
		c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		ft_filler('0', flags->precision - ft_longnbrlen(c));
		ft_putlongnbr(c);
		tab[1] += flags->width;
	}
}
