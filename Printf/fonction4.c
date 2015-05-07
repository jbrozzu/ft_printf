/*
HEADER
*/

#include "ft_printf.h"

void	ft_filler(char c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
}

void	fill_it(t_flags *flags, int size)
{
	if (size > 0)
	{
		if (flags->o_zero && !(flags->precision) && (!(flags->o_min)))
			ft_filler('0', size);
		else
			ft_filler(' ', size);
	}
}

int		absolut_int(int i)
{
	if (i < 0)
		i *= (-1);
	return (i);
}