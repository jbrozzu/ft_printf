/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:37:42 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:38:22 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag(const char *str, t_flags *flags, int *tab)
{
	while (str[tab[0]] == '#' || str[tab[0]] == '+' || str[tab[0]] == '0' ||
			str[tab[0]] == '-' || str[tab[0]] == ' ')
	{
		flags->o_sharp = (str[tab[0]] == '#') ? 1 : 0;
		flags->o_min = (str[tab[0]] == '-') ? 1 : 0;
		flags->o_plus = (str[tab[0]] == '+') ? 1 : 0;
		flags->o_zero = (str[tab[0]] == '0') ? 1 : 0;
		flags->o_space = (str[tab[0]] == ' ') ? 1 : 0;
		tab[0] += 1;
		if ((flags->o_plus == 1 && (str[tab[0]] == ' ' ||
			str[tab[0]] == '0')) || (flags->o_space == 1 &&
			str[tab[0]] == '0' && ft_isdigit(str[tab[0] + 1]) == 1))
		{
			flags->espace_zero = 1;
			tab[0] += 1;
		}
	}
}

void	check_prec(const char *str, t_flags *flags, int *tab, va_list list)
{
	char result[100];

	if (str[tab[0]] == '.')
	{
		tab[0] += 1;
		flags->o_point = 1;
		if (ft_isdigit(str[tab[0]]) == 0 && str[tab[0]] != '*')
			flags->empty_p = 1;
		else
			flags->empty_p = 0;
		if (ft_isdigit(str[tab[0]]) == 1)
		{
			ft_get_next_valor(str, tab, result);
			flags->precision = ft_atoi(result);
		}
		else if (str[tab[0]] == '*')
		{
			flags->precision = va_arg(list, int);
			tab[0] += 1;
		}
	}
	else
		flags->empty_p = 1;
}

void	check_modif(const char *str, t_flags *flags, int *tab)
{
	if (str[tab[0]] == 'h' || str[tab[0]] == 'l' ||
		str[tab[0]] == 'j' || str[tab[0]] == 'z')
	{
		flags->modif1 = str[tab[0]];
		tab[0] += 1;
		if (str[tab[0]] == 'h' || str[tab[0]] == 'l')
		{
			flags->modif2 = str[tab[0]];
			tab[0] += 1;
		}
		else
			flags->modif2 = '\0';
	}
	else
		flags->modif1 = '\0';
}

void	check_type(const char *str, t_flags *flags, int *tab)
{
	if (str[tab[0]] == 's' || str[tab[0]] == 'S' || str[tab[0]] == 'p' ||
		str[tab[0]] == 'd' || str[tab[0]] == 'D' || str[tab[0]] == 'i' ||
		str[tab[0]] == 'o' || str[tab[0]] == 'O' || str[tab[0]] == 'u' ||
		str[tab[0]] == 'U' || str[tab[0]] == 'x' || str[tab[0]] == 'X' ||
		str[tab[0]] == 'c' || str[tab[0]] == 'C' || str[tab[0]] == '%')
	{
		flags->type = str[tab[0]];
		tab[0] += 1;
	}
	else
		flags->type = '\0';
}

void	init_flags(const char *str, t_flags *flags, int *tab, va_list list)
{
	tab[0] += 1;
	check_flag(str, flags, tab);
	check_width(str, flags, tab, list);
	check_prec(str, flags, tab, list);
	check_modif(str, flags, tab);
	check_type(str, flags, tab);
}
