/*
HEADER
*/

#include "ft_printf.h"

void	ft_arg_sort(const char *str, va_list list, int *tab)
{
	t_flags flags;

	ft_bzero(&flags, sizeof(t_flags));
	init_flags(str, &flags, tab, list);
	ft_type_sort(str, &flags, list, tab);
}

int		get_flags(const char *str, va_list list)
{
	int tab[2]; 

	tab[0] = 0;
	tab[1] = 0;
	while (str[tab[0]] != '\0')
	{
		if (str[tab[0]] == '%')
			ft_arg_sort(str, list, tab);
		else
		{
			ft_putchar(str[tab[0]]);
			tab[0] += 1;
			tab[1] += 1;
		}
	}
	return (tab[1]);
}