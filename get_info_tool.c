/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:38:28 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:38:32 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_next_valor(const char *str, int *tab, char *result)
{
	int		i;

	ft_bzero(result, 100);
	i = 0;
	if (ft_isdigit(str[tab[0]]))
	{
		while (ft_isdigit(str[tab[0]]))
		{
			result[i] = str[tab[0]];
			i += 1;
			tab[0] += 1;
		}
	}
	return (result);
}

void	ft_wildcard(t_flags *flags, va_list list, int *tab)
{
	flags->width = va_arg(list, int);
	if (flags->o_sharp == '\0' && flags->o_min == '\0' &&
		flags->o_plus == '\0' && flags->o_zero == '\0' &&
		flags->o_space == '\0' && flags->width < 0)
	{
		flags->o_min = 1;
		flags->width *= (-1);
	}
	tab[0] += 1;
}

void	check_width(const char *str, t_flags *flags, int *tab, va_list list)
{
	char	result[100];

	if (ft_isdigit(str[tab[0]]) == 0 && str[tab[0]] != '*')
		flags->empty_w = 1;
	else
		flags->empty_w = 0;
	if (ft_isdigit(str[tab[0]]) == 1)
	{
		ft_get_next_valor(str, tab, result);
		flags->width = ft_atoi(result);
		if (str[tab[0]] == '*')
			ft_wildcard(flags, list, tab);
	}
	else if (str[tab[0]] == '*')
	{
		ft_wildcard(flags, list, tab);
		if (ft_isdigit(str[tab[0]]) == 1)
		{
			ft_get_next_valor(str, tab, result);
			flags->width = ft_atoi(result);
		}
	}
}
