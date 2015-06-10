/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:33:51 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:34:06 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_linttohexa(unsigned long int nb, char *str, char *hex)
{
	int e;

	e = 1;
	if (nb > 0)
	{
		while ((nb >> 4 * e) > 0)
			e++;
		while (nb > 0)
		{
			str[e-- + 1] = hex[(nb & 0xF)];
			nb >>= 4;
		}
	}
	else
		str[2] = '0';
}

void	arg_is_ptr_flags(t_flags *flags, int *tab, char *str)
{
	if (flags->o_point && (!flags->precision || flags->precision == 0))
	{
		ft_putstr("0x");
		tab[1] += 2;
	}
	else if (flags->o_zero)
		print_ptr_flag_zero(flags, tab, str);
	else if (flags->o_min)
		print_ptr_flag_min(flags, tab, str);
	else
		print_ptr_no_flags(flags, tab, str);
}

void	arg_is_ptr(t_flags *flags, va_list list, int *tab)
{
	char				*str;
	unsigned long int	pt;

	str = ft_strdup(OCTBASE);
	ft_bzero(str + 2, 12);
	pt = va_arg(list, unsigned long int);
	ft_linttohexa(pt, str, MINHEXA);
	arg_is_ptr_flags(flags, tab, str);
}
