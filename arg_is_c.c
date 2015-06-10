/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:39:44 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:39:53 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_is_wchar(t_flags *flags, va_list list, int *tab)
{
	wchar_t c;

	c = va_arg(list, wchar_t);
	if (!flags->o_min)
	{
		if (flags->width - ft_wcharlen(c) > 0)
			fill_it(flags, flags->width - ft_wcharlen(c));
		tab[1] += ft_putwchar(c);
	}
	else
	{
		tab[1] += ft_putwchar(c);
		if (flags->width - ft_wcharlen(c) > 0)
			fill_it(flags, flags->width - ft_wcharlen(c));
	}
}

void	print_char(t_flags *flags, va_list list, int *tab)
{
	int c;

	c = va_arg(list, int);
	if (flags->width - 1 > 0)
		tab[1] += flags->width - 1;
	if (!flags->o_min)
	{
		if (flags->width - 1 > 0)
			fill_it(flags, flags->width - 1);
		if (c >= 0 && c <= 255)
			ft_putchar((char)c);
	}
	else
	{
		if (c >= 0 && c <= 255)
			ft_putchar((char)c);
		if (flags->width - 1 > 0)
			fill_it(flags, flags->width - 1);
	}
	tab[1] += 1;
}

void	arg_is_char(t_flags *flags, va_list list, int *tab)
{
	if (flags->type == 'C' || flags->modif1 == 'l')
		arg_is_wchar(flags, list, tab);
	else
		print_char(flags, list, tab);
}
