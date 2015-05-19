/*
HEADER
*/

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str = "AAAAA";
	int i;
	char c = 'Y';

	i = 42;
	ft_printf("1111 %05c 1111\n", c);
	printf("1111 %05c 1111\n", c);
	return (0);
}


//L'猫'