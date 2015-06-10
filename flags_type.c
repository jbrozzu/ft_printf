/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:37:25 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:37:29 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagstype(t_flags *flags, va_list list, int *tab)
{
	if (flags->type == '%')
		arg_is_mod(flags, tab);
	else if (flags->type == 's' || flags->type == 'S')
		arg_is_string(flags, list, tab);
	else if (flags->type == 'c' || flags->type == 'C')
		arg_is_char(flags, list, tab);
	else if (flags->type == 'd' || flags->type == 'i' || flags->type == 'D')
		arg_is_int(flags, list, tab);
	else if (flags->type == 'p')
		arg_is_ptr(flags, list, tab);
	else if (flags->type == 'x' || flags->type == 'X')
		arg_is_x(flags, list, tab);
	else if (flags->type == 'o' || flags->type == 'O')
		arg_is_octal(flags, list, tab);
	else if (flags->type == 'u' || flags->type == 'U')
		arg_is_unsigned(flags, list, tab);
}

void	ft_type_sort(const char *str, t_flags *flags, va_list list, int *tab)
{
	if (flags->type != '\0')
		ft_flagstype(flags, list, tab);
	else
	{
		if (flags->width - 1 > 0)
		{
			if (!(flags->o_min))
			{
				fill_it(flags, flags->width - 1);
				tab[1] += flags->width - 1;
			}
			else
			{
				ft_putchar(str[tab[0]]);
				tab[1] += flags->width;
				tab[0] += 1;
				fill_it(flags, flags->width - 1);
			}
		}
	}
}
