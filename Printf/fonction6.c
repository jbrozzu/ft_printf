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

void	print_plus(t_flags *flags, int *tab, int c, int *size)
{
	if (flags->o_plus && c >= 0)
	{
		ft_putchar('+');
		tab[1] += 1;
		*size += 1;
	}
}

size_t	ft_nbrlen(int nbr)
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

int		print_int_fill(t_flags *flags, int *tab, int c)
{
	int size;

	size = ft_nbrlen(c);
	if (flags->precision)
		size += (flags->precision - size);
	if ((flags->o_plus && c > 0) || c < 0)
		size += 1;
	if (flags->width && size < flags->width)
		print_int_opt(flags, c, size, tab);
	else
		print_no_min(flags, tab, c);
	if ((flags->o_plus && c >= 0) || c < 0)
		size -= 1;
	if (c < 0)
		size += 1;
	return (size);
}

void	print_int_opt(t_flags *flags, int c, int size, int *tab)
{
	if (flags->o_space)
	{
		ft_putchar(' ');
		tab[1] += 1;
		size += 1;
	}
	tab[1] += flags->width - size;
	if (flags->o_min)
		print_int_rev(flags, tab, size, c);
	else
	{
		print_plus(flags, tab, c, &size);
		if (flags->o_zero || flags->precision)
			c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		if (flags->width)
			fill_it(flags, flags->width - size);
		if (flags->prec)
			ft_filler('0', flags->precision - ft_nbrlen(c));
		ft_putnbr(c);
	}
}