/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_u_umaj_tool.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:42:03 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:42:07 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tool1_u_no_flags(t_flags *flags, unsigned long long int value,
	int *tab, int size)
{
	ft_filler(' ', flags->width - size);
	ft_putlnbr(value);
	tab[1] += flags->width;
}

void	tool2_u_no_flags(t_flags *flags, unsigned long long int value,
	int *tab, int size)
{
	ft_filler('0', flags->precision - size);
	ft_putlnbr(value);
	tab[1] += (flags->precision);
}

void	tool3_u_no_flags(t_flags *flags, unsigned long long int value,
	int *tab, int size)
{
	ft_filler(' ', flags->width - flags->precision);
	ft_filler('0', flags->precision - size);
	ft_putlnbr(value);
	tab[1] += flags->width;
}

void	print_u_no_flags(t_flags *flags, unsigned long long int value, int *tab)
{
	int size;

	size = ft_lnbrlen(value);
	if (flags->width && flags->width > size && (!flags->precision ||
	flags->precision <= size))
		tool1_u_no_flags(flags, value, tab, size);
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= flags->precision))
		tool2_u_no_flags(flags, value, tab, size);
	else if (flags->width && flags->precision &&
		flags->width > flags->precision && flags->precision > size)
		tool3_u_no_flags(flags, value, tab, size);
	else if (flags->empty_w == 1 && flags->o_point && (flags->empty_p == 0 ||
		(flags->empty_p == 1 && flags->precision == 0)) && value == 0)
		return ;
	else
	{
		ft_putlnbr(value);
		tab[1] += size;
	}
}
