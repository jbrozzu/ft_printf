/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:39:27 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 21:11:49 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i += ft_putwchar(*str);
		str++;
	}
	return (i);
}

char	ft_print_w(unsigned char *f, unsigned int e, wchar_t c)
{
	if (e < 0x07FF)
	{
		init_wchar(f, c, 2);
		ft_putnchar(f, 2);
		return (2);
	}
	else if (e < 0xFFFF)
	{
		init_wchar(f, c, 3);
		ft_putnchar(f, 3);
		return (3);
	}
	else
	{
		init_wchar(f, c, 4);
		ft_putnchar(f, 4);
		return (4);
	}
}

int		ft_wnstrlen(wchar_t *str, int n)
{
	int i;

	i = 0;
	while (*str != '\0' && (i + ft_wcharlen(*str)) <= n)
	{
		i += ft_wcharlen(*str);
		str++;
	}
	return (i);
}

int		ft_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i += ft_wcharlen(*str);
		str++;
	}
	return (i);
}

int		ft_wcharlen(wchar_t c)
{
	unsigned int e;

	e = (unsigned int)c;
	if (e > 255 && e < 0x10FFFF)
	{
		if (e < 0x07FF)
			return (2);
		else if (e < 0xFFFF)
			return (3);
		else
			return (4);
	}
	else
		return (1);
}
