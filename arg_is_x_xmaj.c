/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_x_xmaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:42:29 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:42:35 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_inttohexa(unsigned long long int nb, char *str, char *hex)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while ((nb >> (4 * i)) > 0 && i < 16)
			i++;
		i--;
		while (nb > 0)
		{
			str[i--] = hex[(nb & 0xF)];
			nb >>= 4;
		}
	}
	else
		str[0] = '0';
}

void	cast_hexa(unsigned long long int *nb, va_list list, t_flags *flags)
{
	if (flags->modif1 == 'h' && flags->modif2 == 'h')
		*nb = (unsigned char)va_arg(list, int);
	else if (flags->modif1 == 'h' && flags->modif2 == '\0')
		*nb = (unsigned short)va_arg(list, int);
	else if (flags->modif1 == 'j' || flags->modif1 == 'z' ||
		(flags->modif1 == 'l' && flags->modif2 == 'l'))
		*nb = va_arg(list, unsigned long long int);
	else if (flags->modif1 == 'l' && flags->modif2 == '\0')
		*nb = va_arg(list, unsigned long int);
	else
		*nb = va_arg(list, unsigned int);
}

void	arg_is_x_flags(t_flags *flags, int *tab, char *str,
	unsigned long long int value)
{
	if (flags->o_sharp && value > 0)
		print_x_flag_sharp(flags, tab, str);
	else if (flags->o_zero)
		print_x_flag_zero(flags, tab, str, value);
	else if (flags->o_min)
		print_x_flag_min(flags, tab, str, value);
	else
		print_x_no_flags(flags, tab, str, value);
}

void	arg_is_x(t_flags *flags, va_list list, int *tab)
{
	unsigned long long int	value;
	char					str[16];

	ft_bzero(str, 16);
	cast_hexa(&value, list, flags);
	flags->type == 'x' ? ft_inttohexa(value, str, MINHEXA) :
	ft_inttohexa(value, str, MAJHEXA);
	arg_is_x_flags(flags, tab, str, value);
}
