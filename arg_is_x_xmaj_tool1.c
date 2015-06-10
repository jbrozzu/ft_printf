/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_x_xmaj_tool1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 19:42:41 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 19:42:45 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tool1_x_shap(t_flags *flags, int size, char *str, int *tab)
{
	flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	ft_filler('0', flags->precision - size);
	ft_putstr(str);
	tab[1] += (flags->precision + 2);
}

void	tool2_x_shap(t_flags *flags, int size, char *str, int *tab)
{
	ft_filler(' ', flags->width - (flags->precision + 2));
	flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	ft_filler('0', flags->precision - size);
	ft_putstr(str);
	tab[1] += flags->width;
}

void	tool3_x_shap(t_flags *flags, int size, char *str, int *tab)
{
	flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	ft_putstr(str);
	tab[1] += size + 2;
}

void	print_x_flag_sharp(t_flags *flags, int *tab, char *str)
{
	int size;

	size = ft_strlen(str);
	if (!flags->width && flags->o_point && (!flags->precision ||
		flags->precision == 0))
		return ;
	else if (flags->width && flags->width > (size + 2) && (!flags->precision ||
		flags->precision <= size))
	{
		ft_filler(' ', flags->width - (size + 2));
		flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= (flags->precision + 2)))
		tool1_x_shap(flags, size, str, tab);
	else if (flags->width && flags->precision &&
		flags->width > (flags->precision + 2) && flags->precision > size)
		tool2_x_shap(flags, size, str, tab);
	else
		tool3_x_shap(flags, size, str, tab);
}
