/*
HEADER
*/

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str = "AAAAA";       //     %-4.3d    %-10.5d
	int i;
	int j;
	char c = 'Y';
	int k = 42;

	i = ft_printf("i%+di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+5di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+5di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+2di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+2di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+.6di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+.6di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+.2di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+.2di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+10.5di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+10.5di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+2.2di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+2.2di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+5.2di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+5.2di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+2.5di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+2.5di\n", 42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%+5.5di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%+5.5di\n", 42);
	printf("return real : %d\n\n", j);

	/*i = printf("i%-2.2di\n", 42);
	printf("return mine : %d\n", i);
	j = printf("i%-2.2di\n", -42);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%2.5di\n", 427);
	printf("return mine : %d\n", i);
	j = printf("i%2.5di\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%2.5di\n", -427);
	printf("return mine : %d\n", i);
	j = printf("i%2.5di\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%5.2di\n", 427);
	printf("return mine : %d\n", i);
	j = printf("i%5.2di\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%5.2di\n", -427);
	printf("return mine : %d\n", i);
	j = printf("i%5.2di\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%di\n", 427);
	printf("return mine : %d\n", i);
	j = printf("i%di\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%di\n", -427);
	printf("return mine : %d\n", i);
	j = printf("i%di\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%7di\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1%7d1\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%7di\n", -427);
	printf("return mine : %d\n", i);
	j = printf("i%7di\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%2di\n", 427);
	printf("return mine : %d\n", i);
	j = printf("i%2di\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%2di\n", -427);
	printf("return mine : %d\n", i);
	j = printf("i%2di\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%4di\n", 427);
	printf("return mine : %d\n", i);
	j = printf("i%4di\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("i%5di\n", -427);
	printf("return mine : %d\n", i);
	j = printf("i%5di\n", -427);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%0d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%0d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%05d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%5d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%05d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%5d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%02d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%2d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%02d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%2d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%0.6d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%.6d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%0.6d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%.6d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%0.3d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%.3d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%0.2d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%.2d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%0.2d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%.2d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%06d1", 4200);
	printf("      return real : %d\n", j);
	j = printf("1%06d1", 4200);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%06d1", -4200);
	printf("      return real : %d\n", j);
	j = printf("1%06d1", -4200);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%05.10d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%5.10d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%05.10d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%5.10d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%05.5d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%5.5d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%05.5d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%5.5d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%02.2d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%2.2d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%02.2d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%2.2d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%05.2d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%5.2d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%05.2d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%5.2d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%02.5d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%2.5d1", 42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%02.5d1", -42);
	printf("      return real : %d\n", j);
	j = printf("1%2.5d1", -42);
	printf("      return real : %d\n\n", j);

	j = ft_printf("1%0d1", 42);
	printf("      return real : %d\n", j);
	j = printf("1%d1", 42);
	printf("      return real : %d\n\n", j);

	i = ft_printf("1111 %+14.6d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+14.6d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+14.6d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+14.6d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+10d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+10d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+10d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+10d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+2d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+2d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+2d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+2d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+.6d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+14.6d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+.6d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+14.6d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %-7d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %-7d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %-9d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %-9d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %-2d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %-2d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %-3d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %-3d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %-.7d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %-.7d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %-.7d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %-.7d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %7.2d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %7.2d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %.7d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %.7d 1111\n", -427);
	printf("return real : %d\n\n", j);
	
	i = ft_printf("1111 %5.5d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %5.5d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 % 7.7d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 % 7.7d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %08.4d 1111\n", 45);
	printf("return mine : %d\n", i);
	j = printf("1111 %08.4d 1111\n", 45);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %-10.5d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %-10.5d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+d 1111\n", 427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %0d 1111\n", 427);
	printf("return mine : %d\n", i);
	j = printf("1111 %0d 1111\n", 427);
	printf("return real : %d\n\n", j);*/

	return (0);
}


//L'猫'