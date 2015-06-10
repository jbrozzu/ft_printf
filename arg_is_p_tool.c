/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_p_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:34:14 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:34:20 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tool1_ptr_no_flags(t_flags *flags, char *str, int size, int *tab)
{
	ft_putnstr(str, 2);
	ft_filler('0', flags->precision - (size - 2));
	ft_putstrfrom(str, 3);
	tab[1] += (flags->precision + 2);
}

void	tool2_ptr_no_flags(t_flags *flags, char *str, int size, int *tab)
{
	ft_filler(' ', flags->width - (flags->precision + 2));
	ft_putnstr(str, 2);
	ft_filler('0', flags->precision - (size - 2));
	ft_putstrfrom(str, 3);
	tab[1] += flags->width;
}

void	print_ptr_no_flags(t_flags *flags, int *tab, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision <= (size - 2)))
	{
		ft_filler(' ', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > (size - 2) &&
		(!flags->width || flags->width <= (flags->precision + 2)))
		tool1_ptr_no_flags(flags, str, size, tab);
	else if (flags->width && flags->precision &&
		flags->width > (flags->precision + 2) && flags->precision > size)
		tool2_ptr_no_flags(flags, str, size, tab);
	else
	{
		ft_putstr(str);
		tab[1] += size;
	}
}

void	print_ptr_flag_zero(t_flags *flags, int *tab, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && !flags->precision)
	{
		ft_putnstr(str, 2);
		ft_filler('0', flags->width - size);
		ft_putstrfrom(str, 3);
		tab[1] += flags->width;
	}
	else
		print_ptr_no_flags(flags, tab, str);
}

void	print_ptr_flag_min(t_flags *flags, int *tab, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision < (size - 2) || flags->width > (flags->precision + 2)))
	{
		ft_putnstr(str, 2);
		if (flags->precision && flags->precision > (size - 2))
			ft_filler('0', flags->precision - (size - 2));
		ft_putstrfrom(str, 3);
		if (flags->precision && flags->precision > (size - 2))
			ft_filler(' ', flags->width - (flags->precision + 2));
		else
			ft_filler(' ', flags->width - size);
		tab[1] += flags->width;
	}
	else
		print_ptr_no_flags(flags, tab, str);
}
