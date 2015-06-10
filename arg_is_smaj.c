/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_smaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:41:40 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:41:47 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_wstr_rev(t_flags *flags, wchar_t *str, int size)
{
	if (flags->o_point && flags->precision)
		ft_putwnstr(str, flags->precision);
	else
		str ? ft_putwstr(str) : ft_putstr("(null)");
	if (flags->width > size)
	{
		fill_it(flags, flags->width - size);
		size += flags->width - size;
	}
	return (size);
}

void	tool_wstr(t_flags *flags, int *size, wchar_t *str)
{
	if (flags->width >= *size)
	{
		fill_it(flags, flags->width - *size);
		*size += flags->width - *size;
	}
	if (flags->o_point && flags->precision)
		ft_putwnstr(str, flags->precision);
	else
		str ? ft_putwstr(str) : ft_putstr("(null)");
}

void	print_wstr(t_flags *flags, va_list list, int *tab)
{
	wchar_t	*str;
	int		size;

	size = 0;
	str = va_arg(list, wchar_t*);
	if (str == 0)
	{
		ft_putstr("(null)");
		tab[1] += 6;
		return ;
	}
	str ? (size = ft_wstrlen(str)) : (size += 0);
	if ((flags->o_point && flags->precision && str))
		size = ft_wnstrlen(str, flags->precision);
	if (!flags->o_min)
		tool_wstr(flags, &size, str);
	else
		size = print_wstr_rev(flags, str, size);
	tab[1] += size;
}

void	arg_is_wstr(t_flags *flags, va_list list, int *tab)
{
	if (!(flags->o_point) || (flags->o_point && flags->precision))
		print_wstr(flags, list, tab);
	else if ((flags->o_point && (!(flags->precision)) && flags->width))
	{
		fill_it(flags, flags->width);
		tab[1] += flags->width;
	}
}
