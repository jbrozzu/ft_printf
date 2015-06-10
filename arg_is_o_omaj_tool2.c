/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_o_tool2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:41:05 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:41:10 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tool1_oct_sharp(t_flags *flags, int size, char *str, int *tab)
{
	ft_filler(' ', flags->width - (size + 1));
	ft_putchar('0');
	ft_putstr(str);
	tab[1] += flags->width;
}

void	tool2_oct_sharp(t_flags *flags, int size, char *str, int *tab)
{
	ft_putchar('0');
	ft_filler('0', flags->precision - (size + 1));
	ft_putstr(str);
	tab[1] += (flags->precision);
}

void	tool3_oct_sharp(t_flags *flags, int size, char *str, int *tab)
{
	ft_filler(' ', flags->width - (flags->precision));
	ft_putchar('0');
	ft_filler('0', flags->precision - (size + 1));
	ft_putstr(str);
	tab[1] += flags->width;
}

void	tool4_oct_sharp(unsigned long long int value, int *tab,
	char *str, int size)
{
	if (value != 0)
	{
		ft_putchar('0');
		tab[1] += 1;
	}
	ft_putstr(str);
	tab[1] += size;
}

void	print_oct_flag_sharp(t_flags *flags, int *tab,
	unsigned long long int value, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->empty_w && flags->o_point && flags->empty_p && value == 0)
	{
		ft_putchar('0');
		tab[1] += 1;
	}
	else if (flags->width && flags->width > (size + 1) && (!flags->precision ||
		flags->precision <= size))
		tool1_oct_sharp(flags, size, str, tab);
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= (flags->precision + 1)))
		tool2_oct_sharp(flags, size, str, tab);
	else if (flags->width && flags->precision &&
		flags->width > (flags->precision + 1) && flags->precision > size)
		tool3_oct_sharp(flags, size, str, tab);
	else
		tool4_oct_sharp(value, tab, str, size);
}
