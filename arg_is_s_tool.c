/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_s_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:41:30 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:41:35 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tool_string1(t_flags *flags, char *str, int *tab, int size)
{
	ft_filler(' ', flags->width - size);
	ft_putstr(str);
	tab[1] += flags->width;
}

void	tool_string2(t_flags *flags, char *str, int *tab)
{
	if (flags->precision < 0)
	{
		ft_putstr(str);
		tab[1] += ft_strlen(str);
	}
	else
	{
		ft_putnstr(str, flags->precision);
		tab[1] += flags->precision;
	}
}

void	tool_string3(t_flags *flags, char *str, int *tab)
{
	ft_filler(' ', flags->width - flags->precision);
	ft_putnstr(str, flags->precision);
	tab[1] += flags->width;
}
