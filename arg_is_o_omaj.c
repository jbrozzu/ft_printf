/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_o_omaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:40:39 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:40:47 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_linttoct(unsigned long long int nb, char *str)
{
	int			i;

	i = 1;
	if (nb > 0)
	{
		while ((nb >> (3 * i)) > 0)
			i++;
		while (nb > 0)
		{
			str[i - 1] = '0' + (nb & (7 << 0));
			i--;
			nb >>= 3;
		}
	}
	else
		str[0] = '0';
}

void	cast_octal(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->modif1 == 'j')
		*c = (uintmax_t)va_arg(list, uintmax_t);
	else if (flags->modif1 == 'z')
		*c = (ssize_t)va_arg(list, ssize_t);
	else if (flags->modif1 == 'h' && flags->modif2 == 'h' && flags->type != 'O')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->modif1 == 'h')
		*c = (unsigned short)va_arg(list, int);
	else if (flags->modif1 == 'l' && flags->modif2 == '\0')
		*c = (unsigned long int)va_arg(list, unsigned long int);
	else if ((flags->modif1 == 'l' && flags->modif2 == 'l') ||
		flags->type == 'O')
		*c = va_arg(list, unsigned long long int);
	else
		*c = (unsigned int)va_arg(list, unsigned int);
}

void	get_oct_flags(t_flags *flags, int *tab, unsigned long long int value,
	char *str)
{
	if (flags->o_min)
		print_oct_flag_min(flags, tab, value, str);
	else if (flags->o_sharp)
		print_oct_flag_sharp(flags, tab, value, str);
	else if (flags->o_zero)
		print_oct_flag_zero(flags, tab, value, str);
	else
		print_oct_no_flags(flags, tab, value, str);
}

void	arg_is_octal(t_flags *flags, va_list list, int *tab)
{
	unsigned long long int	value;
	char					str[23];
	int						size;

	size = 0;
	ft_bzero(str, 23);
	cast_octal(&value, list, flags);
	if ((flags->type == 'O' &&
		value < ULONG_MAX && value != (unsigned long long int)LONG_MIN) ||
		(flags->type == 'o' && value < LONG_MAX))
	{
		ft_linttoct(value, str);
		get_oct_flags(flags, tab, value, str);
	}
	else
	{
		size += limit_max(flags, value);
		tab[1] += size;
	}
}
