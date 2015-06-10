/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_o_omaj_tool1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:40:52 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:40:57 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tool1_oct_no_flags(t_flags *flags, int size, char *str, int *tab)
{
	ft_filler('0', flags->precision - size);
	ft_putstr(str);
	tab[1] += (flags->precision);
}

void	tool2_oct_no_flags(t_flags *flags, int size, char *str, int *tab)
{
	ft_filler(' ', flags->width - flags->precision);
	ft_filler('0', flags->precision - size);
	ft_putstr(str);
	tab[1] += flags->width;
}

void	print_oct_no_flags(t_flags *flags, int *tab,
	unsigned long long int value, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
	flags->precision <= size))
	{
		ft_filler(' ', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= flags->precision))
		tool1_oct_no_flags(flags, size, str, tab);
	else if (flags->width && flags->precision &&
		flags->width > flags->precision && flags->precision > size)
		tool2_oct_no_flags(flags, size, str, tab);
	else if (flags->empty_w == 1 && flags->o_point && (flags->empty_p == 0 ||
		(flags->empty_p == 1 && flags->precision == 0)) && value == 0)
		return ;
	else
	{
		ft_putstr(str);
		tab[1] += size;
	}
}

void	print_oct_flag_min(t_flags *flags, int *tab,
	unsigned long long int value, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision < size || flags->width > flags->precision))
	{
		if (flags->precision && flags->precision > size)
			ft_filler('0', flags->precision - size);
		ft_putstr(str);
		if (flags->precision && flags->precision > size)
			ft_filler(' ', flags->width - flags->precision);
		else
			ft_filler(' ', flags->width - size);
		tab[1] += flags->width;
	}
	else
		print_oct_no_flags(flags, tab, value, str);
}

void	print_oct_flag_zero(t_flags *flags, int *tab,
	unsigned long long int value, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && !flags->o_point && !flags->precision &&
		flags->width > size)
	{
		ft_filler('0', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else
		print_oct_no_flags(flags, tab, value, str);
}
