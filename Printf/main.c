/*
HEADER
*/

#include "ft_printf.h"
#include <locale.h>


int		main(void)
{
	char *str = "Salut!";
	int i;
	int j;
	char c;
	int k = 42;

	char* l = setlocale(LC_ALL, "");
	
	j = printf("i%.0d   %.di\n", 0, 0);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%.0d   %.di\n", 0, 0);
	printf("return mine : %d\n\n", i - 3);

	j = printf("{%*3d}", 0, 0);
	printf("return real : %d\n", j);
	i = ft_printf("{%*3d}", 0, 0);
	printf("return mine : %d\n\n", i);

	j = printf("{%3d}", 0);
	printf("return real : %d\n", j);
	i = ft_printf("{%3d}", 0);
	printf("return mine : %d\n\n", i);


	j = printf("{%05.*d}", 0, 42);
	printf("return real : %d\n", j);
	i = ft_printf("{%05.*d}", 0, 42);
	printf("return mine : %d\n\n", i);

	j = printf("{%10p}", 0);
	printf("return real : %d\n", j);
	i = ft_printf("{%10p}", 0);
	printf("return mine : %d\n\n", i);


	j = printf("i%.0di\n", 42);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%.*di\n", 0, 42);
	printf("return mine : %d\n\n", i - 3);


	j = printf("{% 5d}\n", 42);
	printf("return real : %d\n", j - 1);
	i = ft_printf("{% 5d}\n", 42);
	printf("return mine : %d\n\n", i - 1);

	j = printf("{% 1d}\n", 0);
	printf("return real : %d\n", i - 1);
	i = ft_printf("{% 1d}\n", 0);
	printf("return mine : %d\n\n", i - 1);

	j = printf("{% .5d}\n", 0);
	printf("return real : %d\n", j - 1);
	i = ft_printf("{% .5d}\n", 0);
	printf("return mine : %d\n\n", i - 1);

	j = printf("{% .2d}\n", 0);
	printf("return real : %d\n", j - 1);
	i = ft_printf("{% .2d}\n", 0);
	printf("return mine : %d\n\n", i - 1);

	j = printf("{% 7.5d}\n", 0);
	printf("return real : %d\n", j - 1);
	i = ft_printf("{% 7.5d}\n", 0);
	printf("return mine : %d\n\n", i - 1);

	i = ft_printf("i%si\n", "bonjour");
	printf("return mine : %d\n", i - 3);
	j = printf("i%si\n", "bonjour");
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%di\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%di\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%pi\n", &c);
	printf("return mine : %d\n", i - 3);
	j = printf("i%pi\n", &c);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%%i\n");
	printf("return mine : %d\n", i - 3);
	j = printf("i%%i\n");
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Si\n", L"暖炉");
	printf("return mine : %d\n", i - 3);
	j = printf("i%Si\n", L"暖炉");
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Di\n", LONG_MAX);
	printf("return mine : %d\n", i - 3);
	j = printf("i%Di\n", LONG_MAX);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%ii\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%ii\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%oi\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%oi\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Oi\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%Oi\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%ui\n", 100000);
	printf("return mine : %d\n", i - 3);
	j = printf("i%ui\n", 100000);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Ui\n", ULONG_MAX);
	printf("return mine : %d\n", i - 3);
	j = printf("i%Ui\n", ULONG_MAX);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%xi\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%xi\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Xi\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%Xi\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%ci\n", 'c');
	printf("return mine : %d\n", i - 3);
	j = printf("i%ci\n", 'c');
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Ci\n", L'플');
	printf("return mine : %d\n", i - 3);
	j = printf("i%Ci\n", L'플');
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%zdi\n", -9223372036854775);
	printf("return mine : %d\n", i - 3);
	j = printf("i%zdi\n", -9223372036854775);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%jdi\n", -9223372036854775);
	printf("return mine : %d\n", i - 3);
	j = printf("i%jdi\n", -9223372036854775);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%hdi\n", -9223372036854775);
	printf("return mine : %d\n", i - 3);
	j = printf("i%hdi\n", -9223372036854775);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%hhdi\n", -9223372036854775);
	printf("return mine : %d\n", i - 3);
	j = printf("i%hhdi\n", -9223372036854775);
	printf("return real : %d\n\n", j - 3);
	
	i = ft_printf("%O%O%O%O%O%O\n", 42, 42, 42, 42, 42, 42);
	printf("return mine : %d\n", i - 3);
	j = printf("%O%O%O%O%O%O\n", 42, 42, 42, 42, 42, 42);
	printf("return real : %d\n\n", j - 3);

	j = printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("return real : %d\n", j - 1);
	i = ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("return mine : %d\n\n", i - 1);

	j = printf("i{%+03d}i\n", 0);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i{%+03d}i\n", 0);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i{% 03d}i\n", 0);
	printf("return real : %d\n", j - 3);
	i = printf("i{% 03d}i\n", 0);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i{%+03d}i\n", 12);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i{%+03d}i\n", 12);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i{%+03d}i\n", 123456);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i{%+03d}i\n", 123456);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-ui\n", LONG_MAX);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-ui\n", LONG_MAX);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-.ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-.ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-7ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-7ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-3ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-3ui\n", 4242);
	printf("return mine : %d\n\n", i - 3); 

	j = printf("i%-.7ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-.7ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-.3ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-.3ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-2.2ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-2.2ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-7.2ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-7.2ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-2.7ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-2.7ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-7.7ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-7.7ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-10.7ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-10.7ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-7.ui\n", 4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-7.ui\n", 4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-.ui\n", 0);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-.ui\n", 0);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-ui\n", -4242);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-ui\n", -4242);
	printf("return mine : %d\n\n", i - 3);

	j = printf("i%-5ui\n", 42);
	printf("return real : %d\n", j - 3);
	i = ft_printf("i%-5ui\n", 42);
	printf("return mine : %d\n\n", i - 3);  


	i = ft_printf("i%03Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%03Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%07Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%07Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%0.3Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%0.3Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%0.7Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%0.7Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%05.5Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%05.5Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%08.5Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%08.5Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%07.3Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%07.3Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%03.7Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%03.7Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%03.2Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%03.2Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%07.Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%07.Xi\n", 2003);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%03.Xi\n", 2003);
	printf("return mine : %d\n", i - 3);
	j = printf("i%03.Xi\n", 2003);
	printf("return real : %d\n\n", j - 3); 

	i = ft_printf("i%si\n", "bonjour");
	printf("return mine : %d\n", i - 3);
	j = printf("i%si\n", "bonjour");
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%di\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%di\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%pi\n", &c);
	printf("return mine : %d\n", i - 3);
	j = printf("i%pi\n", &c);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%%i\n");
	printf("return mine : %d\n", i - 3);
	j = printf("i%%i\n");
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Si\n", L"暖炉");
	printf("return mine : %d\n", i - 3);
	j = printf("i%Si\n", L"暖炉");
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Di\n", LONG_MAX);
	printf("return mine : %d\n", i - 3);
	j = printf("i%Di\n", LONG_MAX);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%ii\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%ii\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%oi\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%oi\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Oi\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%Oi\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%ui\n", 100000);
	printf("return mine : %d\n", i - 3);
	j = printf("i%ui\n", 100000);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Ui\n", ULONG_MAX);
	printf("return mine : %d\n", i - 3);
	j = printf("i%Ui\n", ULONG_MAX);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%xi\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%xi\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Xi\n", 42);
	printf("return mine : %d\n", i - 3);
	j = printf("i%Xi\n", 42);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%ci\n", 'c');
	printf("return mine : %d\n", i - 3);
	j = printf("i%ci\n", 'c');
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%Ci\n", L'플');
	printf("return mine : %d\n", i - 3);
	j = printf("i%Ci\n", L'플');
	printf("return real : %d\n\n", j - 3);
	
	i = ft_printf("i%4.si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%4.si\n", str);
	printf("return real : %d\n\n", j - 3); 

	i = ft_printf("i%3.si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%3.si\n", str);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%8.si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%8.si\n", str);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%8.si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%8.si\n", str);
	printf("return real : %d\n\n", j - 3);
	
	i = ft_printf("i%0.3si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%0.3si\n", str);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%0.8si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%0.8si\n", str);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%04.3si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%04.3si\n", str);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%08.7si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%08.7si\n", str);
	printf("return real : %d\n\n", j - 3);


	i = ft_printf("i%08.2si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%08.2si\n", str);
	printf("return real : %d\n\n", j - 3);

	i = ft_printf("i%04.8si\n", str);
	printf("return mine : %d\n", i - 3);
	j = printf("i%04.8si\n", str);
	printf("return real : %d\n\n", j - 3);    


	i = ft_printf("i%2.2pi\n", &k);
	printf("return mine : %d\n", i);
	j = printf("i%2.2pi\n", &k);
	printf("return real : %d\n\n", j);


	i = ft_printf("i%5.2pi\n", &k);
	printf("return mine : %d\n", i);
	j = printf("i%5.2pi\n", &k);
	printf("return real : %d\n\n", j);


	i = ft_printf("i%2.5pi\n", &k);
	printf("return mine : %d\n", i);
	j = printf("i%2.5pi\n", &k);
	printf("return real : %d\n\n", j);


	i = ft_printf("i%5.5pi\n", &k);
	printf("return mine : %d\n", i);
	j = printf("i%5.5pi\n", &k);
	printf("return real : %d\n\n", j);

	i = printf("i%-2.2di\n", -42);
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

	j = ft_printf("1%0d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%0d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%0d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%0d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%05d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%05d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%05d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%05d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%02d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%02d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%02d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%02d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%0.6d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%0.6d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%0.6d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%0.6d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%0.3d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%0.3d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%0.2d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%0.2d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%0.2d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%0.2d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%06d1\n", 4200);
	printf("return real : %d\n", j);
	j = printf("1%06d1\n", 4200);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%06d1\n", -4200);
	printf("return real : %d\n", j);
	j = printf("1%06d1\n", -4200);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%05.10d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%5.10d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%05.10d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%5.10d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%05.5d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%5.5d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%05.5d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%5.5d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%02.2d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%2.2d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%02.2d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%2.2d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%05.2d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%5.2d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%05.2d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%5.2d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%02.5d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%2.5d1\n", 42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%02.5d1\n", -42);
	printf("return real : %d\n", j);
	j = printf("1%2.5d1\n", -42);
	printf("return real : %d\n\n", j);

	j = ft_printf("1%0d1\n", 42);
	printf("return real : %d\n", j);
	j = printf("1%d1\n", 42);
	printf("return real : %d\n\n", j);

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

	i = ft_printf("1111 %+14.6d 1111\n", -427);
	printf("return mine : %d\n", i);
	j = printf("1111 %+14.6d 1111\n", -427);
	printf("return real : %d\n\n", j);

	i = ft_printf("1111 %+14.6d 1111\n", 427);
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
	printf("return real : %d\n\n", j);    
	return (0);
}


//L'猫'
