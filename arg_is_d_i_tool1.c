/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_d_i_tool1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:31:24 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:31:28 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_no_size(t_flags *flags, int *tab, int c)
{
	if (c < 0 || (flags->o_plus && c >= 0))
		tab[1] += 1;
	if (flags->o_plus && c >= 0)
		ft_putchar('+');
	ft_putnbr(c);
	tab[1] += ft_nbrlen(c);
}

void	tool_print_width(t_flags *flags, int c, int size)
{
	if (flags->o_plus && c >= 0)
	{
		ft_putchar('+');
		ft_filler('0', flags->width - size);
	}
	else if (flags->espace_zero == 1)
		ft_filler('0', flags->width - size);
	else
		ft_filler(' ', flags->width - size);
}

void	print_width_no_prec(t_flags *flags, int *tab, int c)
{
	int size;

	size = (c >= 0) ? ft_nbrlen(c) : ft_nbrlen(c) + 1;
	if (flags->o_plus && c >= 0)
		size += 1;
	if (flags->width > size)
	{
		if (c == 0)
			tool_print_width(flags, c, size);
		else
		{
			ft_filler(' ', flags->width - size);
			if (flags->o_plus && c >= 0)
				ft_putchar('+');
		}
		ft_putnbr(c);
		tab[1] += flags->width;
	}
	else
		print_no_size(flags, tab, c);
}

void	print_width_prec_rev(t_flags *flags, int *tab, int c)
{
	int i;
	int size;

	i = 0;
	if (c < 0)
	{
		size = ft_nbrlen(c) + 1;
		i += 1;
		c = -c;
		ft_putchar('-');
	}
	else
		size = ft_nbrlen(c);
	if (flags->precision && flags->precision > ft_nbrlen(c))
		ft_filler('0', flags->precision - ft_nbrlen(c));
	ft_putnbr(c);
	if (flags->precision && flags->precision > ft_nbrlen(c))
		ft_filler(' ', flags->width - (flags->precision + i));
	else
		ft_filler(' ', flags->width - size);
	tab[1] += flags->width;
}

void	print_prec_no_width(t_flags *flags, int *tab, int c)
{
	if (flags->precision > ft_nbrlen(c))
	{
		if (flags->o_plus && c >= 0)
		{
			ft_putchar('+');
			tab[1] += 1;
		}
		c < 0 ? (c = -c, ft_putchar('-'), tab[1] += 1) : (c += 0);
		ft_filler('0', flags->precision - ft_nbrlen(c));
		ft_putnbr(c);
		tab[1] += flags->precision;
	}
	else
		print_no_size(flags, tab, c);
}
