/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:34:29 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:34:35 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_is_mod(t_flags *flags, int *tab)
{
	if (flags->type == '%')
	{
		if (!flags->o_min)
		{
			if (flags->width - 1 > 0)
				fill_it(flags, flags->width - 1);
			ft_putchar('%');
		}
		else
		{
			ft_putchar('%');
			if (flags->width - 1 > 0)
				fill_it(flags, flags->width - 1);
		}
	}
	if (flags->width)
		tab[1] += flags->width;
	else
		tab[1] += 1;
}
