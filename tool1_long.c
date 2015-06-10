/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool1_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:38:52 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 18:38:57 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(int nbr)
{
	size_t i;

	i = 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr / 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_putlnbr(unsigned long long int nbr)
{
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putlnbr(nbr / 10);
		ft_putlnbr(nbr % 10);
	}
}

int		ft_lnbrlen(unsigned long long int nbr)
{
	int i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
