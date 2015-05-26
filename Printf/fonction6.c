/*
HEADER
*/

#include "ft_printf.h"

int		ft_longnbrlen(long int nb)
{
	int i;

	i = 1;
	if (nb < 0)
		nb = -nb;
	while (nb > 9)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	ft_putlongnbr(long int nb)
{
	if (nb >= 0 && nb <= 9)
		ft_putchar('0' + nb);
	else
	{
		ft_putlongnbr(nb / 10);
		ft_putlongnbr(nb % 10);
	}
}

void	print_plus(t_flags *flags, int c)
{
	if (flags->o_plus && c > 0)
		ft_putchar('+');
}

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