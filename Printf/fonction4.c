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
	if (flags->o_zero && !(flags->precision) && (!(flags->o_min)))
		ft_filler('0', size);
	else
		ft_filler(' ', size);
}