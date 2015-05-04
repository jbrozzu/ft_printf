#include "includes/ft_printf.h"
#include <stdio.h>

int		main (void)
{
	int a = 43;
	int *i = &a;
	char *str = "bah oui!";

	ft_printf("mine : %9.3s\n", str);
	printf("real : %S\n", i);
	return (0);
}
