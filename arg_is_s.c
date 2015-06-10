/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:41:18 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:41:25 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str_no_flags(t_flags *flags, int *tab, int size, char *str)
{
	if (flags->o_point && (flags->precision == 0 ||
		flags->empty_p == 1) && !flags->width)
		return ;
	else if (flags->width && flags->o_point && !flags->precision)
	{
		ft_filler(' ', flags->width);
		tab[1] += flags->width;
	}
	else if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision >= size))
		tool_string1(flags, str, tab, size);
	else if (flags->precision && flags->precision < size && (!flags->width ||
		flags->width <= flags->precision))
		tool_string2(flags, str, tab);
	else if (flags->precision && flags->precision < size && flags->width &&
		flags->width > flags->precision)
		tool_string3(flags, str, tab);
	else
	{
		ft_putstr(str);
		tab[1] += size;
	}
}

void	print_str_min(t_flags *flags, int *tab, int size, char *str)
{
	if (flags->width && flags->o_point && !flags->precision)
	{
		ft_filler(' ', flags->width);
		tab[1] += flags->width;
	}
	else if (flags->width && ((!flags->precision && flags->width > size) ||
		(flags->precision && ((flags->precision < size && flags->width >
		flags->precision) || (flags->precision > size &&
		flags->width > size)))))
	{
		if (flags->precision && flags->precision < size)
		{
			ft_putnstr(str, flags->precision);
			ft_filler(' ', flags->width - flags->precision);
			tab[1] += flags->width;
		}
		else
		{
			ft_putstr(str);
			ft_filler(' ', flags->width - size);
			tab[1] += flags->width;
		}
	}
	else
		print_str_no_flags(flags, tab, size, str);
}

void	print_str_zero(t_flags *flags, int *tab, int size, char *str)
{
	if (flags->width && flags->o_point && !flags->precision)
	{
		ft_filler('0', flags->width);
		tab[1] += flags->width;
	}
	else if (flags->width && ((!flags->precision && flags->width > size) ||
		(flags->precision && ((flags->precision < size && flags->width >
		flags->precision) || (flags->precision > size &&
		flags->width > size)))))
	{
		if (flags->precision && flags->precision < size)
		{
			ft_filler('0', flags->width - flags->precision);
			ft_putnstr(str, flags->precision);
		}
		else
		{
			ft_filler('0', flags->width - size);
			ft_putstr(str);
		}
		tab[1] += flags->width;
	}
	else
		print_str_no_flags(flags, tab, size, str);
}

void	print_string(t_flags *flags, va_list list, int *tab)
{
	char	*str;
	int		size;

	str = va_arg(list, char*);
	if (str == 0 && !(flags->o_point))
	{
		ft_putstr("(null)");
		tab[1] += 6;
		return ;
	}
	size = (str == 0) ? 0 : ft_strlen(str);
	if (flags->o_zero)
		print_str_zero(flags, tab, size, str);
	else if (flags->o_min)
		print_str_min(flags, tab, size, str);
	else
		print_str_no_flags(flags, tab, size, str);
}

void	arg_is_string(t_flags *flags, va_list list, int *tab)
{
	if ((flags->type == 's' && flags->modif1 == 'l') || flags->type == 'S')
		arg_is_wstr(flags, list, tab);
	else
		print_string(flags, list, tab);
}
