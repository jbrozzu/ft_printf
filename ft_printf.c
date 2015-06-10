/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:37:33 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:37:37 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conv(const char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		check_str_ex(const char *str)
{
	if (str != NULL && str[0] != '\0')
		return (1);
	else
		return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	list;
	int		ret;

	ret = 0;
	if (check_str_ex(format) == 1)
	{
		va_start(list, format);
		if (check_conv(format) == 1)
			ret = get_flags(format, list);
		else
		{
			ft_putstr(format);
			ret = ft_strlen(format);
		}
	}
	va_end(list);
	return (ret);
}
