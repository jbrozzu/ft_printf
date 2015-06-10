/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_d_i_tool2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:31:39 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:31:43 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width_prec(t_flags *flags, int *tab, int c)
{
	int i;

	i = 0;
	if (c < 0 || (flags->o_plus && c >= 0))
		i += 1;
	if (flags->precision >= flags->width)
		print_prec_no_width(flags, tab, c);
	else
	{
		if (flags->width > (flags->precision + i))
			ft_filler(' ', flags->width - (flags->precision + i));
		if (flags->o_plus && c >= 0)
			ft_putchar('+');
		c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		ft_filler('0', flags->precision - ft_nbrlen(c));
		ft_putnbr(c);
		tab[1] += flags->width;
	}
}

void	check_width_prec(t_flags *flags, int *tab, int c)
{
	int size;

	size = (c >= 0) ? ft_nbrlen(c) : ft_nbrlen(c) + 1;
	if (flags->width < size && flags->precision < ft_nbrlen(c))
		print_no_size(flags, tab, c);
	else if (flags->width > size && flags->precision < ft_nbrlen(c))
		print_width_no_prec(flags, tab, c);
	else if (flags->width < size && flags->precision > ft_nbrlen(c))
		print_prec_no_width(flags, tab, c);
	else
		print_width_prec(flags, tab, c);
}

void	print_no_flags(t_flags *flags, int *tab, int c)
{
	if (flags->o_point && (flags->precision == 0 ||
		flags->empty_p == 1) && c == 0)
		return ;
	else if (!flags->width && !flags->precision)
		print_no_size(flags, tab, c);
	else if (flags->width && !flags->precision)
		print_width_no_prec(flags, tab, c);
	else if (!flags->width && flags->precision)
		print_prec_no_width(flags, tab, c);
	else
		check_width_prec(flags, tab, c);
}

void	print_flag_zero(t_flags *flags, int *tab, int c)
{
	int size;

	size = (c >= 0) ? ft_nbrlen(c) : ft_nbrlen(c) + 1;
	if (flags->width && flags->width > size && (flags->empty_p == 1 ||
		flags->precision < 0))
	{
		c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		ft_filler('0', flags->width - size);
		ft_putnbr(c);
		tab[1] += flags->width;
	}
	else
		print_no_flags(flags, tab, c);
}

void	print_flag_space(t_flags *flags, int *tab, int c)
{
	int size;

	size = (c >= 0) ? ft_nbrlen(c) : ft_nbrlen(c) + 1;
	if (c == 0 && flags->width > size)
	{
		ft_putchar(' ');
		tab[1] += 1;
		flags->width -= 1;
		print_no_flags(flags, tab, c);
	}
	else if (c >= 0 && ((flags->width <= size && !flags->precision) ||
		(flags->precision && (!flags->width || flags->width <= size)) ||
		(flags->width == flags->precision)))
	{
		ft_putchar(' ');
		tab[1] += 1;
		print_no_flags(flags, tab, c);
	}
	else
		print_no_flags(flags, tab, c);
}
