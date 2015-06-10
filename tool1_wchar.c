/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool1_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:39:02 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:39:06 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_wchar(unsigned char *f, wchar_t c, int mode)
{
	if (mode == 2)
	{
		f[0] = (((c & 0x07c0) >> 6) + 0xC0);
		f[1] = (((c & 0x003F)) + 0x80);
	}
	if (mode == 3)
	{
		f[0] = (((c & 0xF000) >> 12) + 0xE0);
		f[1] = (((c & 0x0FC0) >> 6) + 0x80);
		f[2] = (((c & 0x003F)) + 0x80);
	}
	if (mode == 4)
	{
		f[0] = (((c & 0x1C0000) >> 18) + 0xF0);
		f[1] = (((c & 0x03F000) >> 12) + 0x80);
		f[2] = (((c & 0x0FC0) >> 6) + 0x80);
		f[3] = (((c & 0x003F)) + 0x80);
	}
}

void	ft_putnchar(unsigned char *f, int size)
{
	int i;

	i = 0;
	while (i != size)
	{
		write(1, &f[i], 1);
		i++;
	}
}

char	ft_putwchar(wchar_t c)
{
	unsigned char	f[4];
	unsigned int	e;

	e = (unsigned int)c;
	ft_bzero(f, 4);
	if (c >= 0 && c <= 255)
	{
		ft_putchar(c);
		return (1);
	}
	else if (e > 255 && e < 0x10FFFF)
		return (ft_print_w(f, e, c));
	return (1);
}

int		ft_putwnstr(wchar_t *str, int n)
{
	int i;

	i = 0;
	while (*str != '\0' && (i + ft_wcharlen(*str)) <= n)
	{
		i += ft_putwchar(*str);
		str++;
	}
	return (i);
}
