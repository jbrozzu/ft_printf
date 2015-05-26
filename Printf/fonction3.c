/*
HEADER
*/

#include "ft_printf.h"
#include <stdio.h>



//------------------------------------------------------------------------------

/*
int		print_wstr_rev(t_flags *flags, wchar_t *str, int size)
{
	if (flags->optdot && flags->prec)
		ft_putwnstr(str, flags->prec);
	else
		str ? ft_putwstr(str) : ft_putstr("(null)");
	if (flags->min_size > size)
	{
		fill_it(flags, flags->min_size - size);
		size += flags->min_size - size;
	}
	return (size);
}

void	print_wstr(t_flags *flags, va_list list, int *i)
{
	wchar_t	*str;
	int		size;

	size = 0;
	str = va_arg(list, wchar_t*);
	str ? (size = ft_wstrlen(str)) : (size += 6);
	if ((flags->optdot && flags->prec && str))
		size = ft_wnstrlen(str, flags->prec);
	if (!flags->optmin)
	{
		if (flags->min_size >= size)
		{
			fill_it(flags, flags->min_size - size);
			size += flags->min_size - size;
		}
		if (flags->optdot && flags->prec)
			ft_putwnstr(str, flags->prec);
		else
			str ? ft_putwstr(str) : ft_putstr("(null)");
	}
	else
		size = print_wstr_rev(flags, str, size);
	i[1] += size;
}

void	arg_is_wstr(t_flags *flags, va_list list, int *i)
{
	if (!(flags->optdot) || (flags->optdot && flags->prec) || flags->optsharp)
		print_wstr(flags, list, i);
	else if ((flags->optdot && (!(flags->prec)) && flags->min_size))
	{
		fill_it(flags, flags->min_size);
		i[1] += flags->min_size;
	}



//--------------------------------------------------------------


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

void	cast_unsigned(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->formf == 'h' && flags->formt == 'h' && flags->type != 'U')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->formf == 'h')
		*c = (unsigned short)va_arg(list, int);
	else
		*c = va_arg(list, unsigned long long int);
}

void	print_unsigned(t_flags *flags, va_list list, int *i)
{
	unsigned long long int	pt;
	int						size;

	cast_unsigned(&pt, list, flags);
	size = ft_lnbrlen(pt);
	if (flags->min_size > size + flags->prec)
		ft_filler(' ', flags->min_size - flags->prec);
	if (flags->prec)
	{
		ft_filler('0', flags->prec - size);
		size += flags->prec - size;
	}
	if (flags->min_size > flags->prec + size)
		size += flags->min_size - size;
	ft_putlnbr(pt);
	i[1] += size;
}

void	arg_is_unsigned(t_flags *flags, va_list list, int *i)
{
	if ((!(flags->optdot)) || (flags->optdot && flags->prec))
	{
		if (flags->type == 'u' || flags->type == 'U')
			print_unsigned(flags, list, i);
	}



//-----------------------------------------------------------------------------


void	print_loct(t_flags *flags, int *i, unsigned long long pt, char *str)
{
	int size;

	size = 0;
	pt > 0 && flags->optsharp ? (size += 1) : (size += 0);
	ft_linttoct(pt, str);
	size += ft_strlen(str);
	if (flags->min_size > size + flags->prec)
		ft_filler(' ', flags->min_size - flags->prec);
	if (flags->prec)
	{
		ft_filler('0', flags->prec - size);
		size += flags->prec - size;
	}
	ft_putstr(str);
	if (flags->min_size > flags->prec + size)
		size += flags->min_size - size;
	i[1] += size;
}

void	print_octal(t_flags *flags, va_list list, int *i)
{
	unsigned long long int	pt;
	char					str[23];
	int						size;

	ft_bzero(str, 23);
	cast_octal(&pt, list, flags);
	size = 0;
	if (pt > 0 && flags->optsharp)
	{
		ft_putchar('0');
		size++;
	}
	if ((flags->type == 'O' && pt < ULONG_MAX && pt \
	!= (unsigned long long)LONG_MIN) || (flags->type == 'o' && pt < LONG_MAX))
		print_loct(flags, i, pt, str);
	else
	{
		size += max_value(flags, pt);
		i[1] += size;
	}
}

void	cast_octal(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->formf == 'h' && flags->formt == 'h' && flags->type != 'O')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->formf == 'h')
		*c = (unsigned short)va_arg(list, int);
	else
		*c = (unsigned long long int)va_arg(list, unsigned long long int);
}

void	arg_is_octal(t_flags *flags, va_list list, int *i)
{
	if ((!(flags->optdot)) || (flags->optdot && flags->prec) || flags->optsharp)
	{
		if (flags->type == 'o' || flags->type == 'O')
			print_octal(flags, list, i);
	}
}


//---------------------------------------------------------------------------


void	ft_inttohexa(unsigned long long int nb, char *str, char *hex)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while ((nb >> (4 * i)) > 0 && i < 16)
			i++;
		i--;
		while (nb > 0)
		{
			str[i--] = hex[(nb & 0xF)];
			nb >>= 4;
		}
	}
	else
		str[0] = '0';
}

void	cast_hexa(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->formf == 'h' && flags->formt == 'h')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->formf == 'h' && flags->formt == '\0')
		*c = (unsigned short)va_arg(list, int);
	else
		*c = va_arg(list, unsigned long long int);
}

void	print_x(t_flags *flags, va_list list, int *i)
{
	unsigned long long int	pt;
	char					str[16];

	ft_bzero(str, 16);
	cast_hexa(&pt, list, flags);
	if (pt > 0 && flags->optsharp)
		flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X"), i[1] += 2;
	flags->type == 'x' ? ft_inttohexa(pt, str, HEXMIN) :\
	ft_inttohexa(pt, str, HEXMAJ);
	if (flags->min_size > (int)(flags->prec + ft_strlen(str)))
	{
		flags->prec ? fill_it(flags, flags->min_size - flags->prec) : \
		fill_it(flags, flags->min_size - ft_strlen(str));
		flags->prec ? (i[1] += flags->min_size - flags->prec) :\
		(i[1] += flags->min_size - ft_strlen(str));
	}
	if (flags->prec)
	{
		ft_filler('0', flags->prec - ft_strlen(str));
		i[1] += flags->prec - ft_strlen(str);
	}
	ft_putstr(str);
	i[1] += ft_strlen(str);
}

void	arg_is_x(t_flags *flags, va_list list, int *i)
{
	if ((!(flags->optdot)) || (flags->optdot && flags->prec))
	{
		if (flags->type == 'x' || flags->type == 'X')
			print_x(flags, list, i);
	}
}


//---------------------------------------------------------------------


void	ft_linttohexa(unsigned long int nb, char *str, char *hex)
{
	int e;

	e = 1;
	if (nb > 0)
	{
		while ((nb >> 4 * e) > 0)
			e++;
		while (nb > 0)
		{
			str[e-- + 1] = hex[(nb & 0xF)];
			nb >>= 4;
		}
	}
	else
		str[2] = '0';
}

void	print_ptr(t_flags *flags, va_list list, int *i)
{
	unsigned long int	pt;
	char				*str;
	int					size;

	str = ft_strdup(OXMIN);
	ft_bzero(str + 2, 12);
	pt = va_arg(list, unsigned long int);
	ft_linttohexa(pt, str, HEXMIN);
	size = ft_strlen(str);
	flags->min_size - size > 0 ? \
	(fill_it(flags, flags->min_size - size), i[1] += flags->min_size - size) :
	(size += 0);
	ft_putstr(str);
	if ((flags->optdot && flags->prec) && flags->prec > size)
	{
		ft_filler('0', flags->prec - (size - 2));
		i[1] += flags->prec - (size - 2);
	}
	i[1] += ft_strlen(str);
}

void	print_rev_ptr(t_flags *flags, va_list list, int *i)
{
	unsigned long int	pt;
	char				*str;
	int					size;

	str = ft_strdup(OXMIN);
	ft_bzero(str + 2, 12);
	pt = va_arg(list, unsigned long int);
	ft_linttohexa(pt, str, HEXMIN);
	size = ft_strlen(str);
	ft_putstr(str);
	if ((flags->optdot && flags->prec) && flags->prec > size)
	{
		ft_filler('0', flags->prec - (size - 2));
		i[1] += flags->prec - (size - 2);
	}
	flags->min_size - size > 0 ? \
	(fill_it(flags, flags->min_size - size), i[1] += flags->min_size - size) :
	(size += 0);
	i[1] += ft_strlen(str);
}

void	arg_is_ptr(t_flags *flags, va_list list, int *i)
{
	if (!(flags->optdot) || (flags->optdot && flags->prec) || flags->optsharp)
	{
		if (flags->optmin || flags->optzero)
			print_rev_ptr(flags, list, i);
		else
			print_ptr(flags, list, i);
	}
	else
	{
		ft_putstr("0x");
		i[1] += 2;
	}
} */


//-------------------------------------------------------------------------


void	print_longint_opt(t_flags *flags, long int l, int size, int *tab)
{
	tab[1] += flags->width - size;
	if (flags->o_min)
	{
		flags->o_min && l > 0 ? (ft_putchar('+'), tab[1]++) : (tab[1] += 0);
		if (flags->precision)
			ft_filler('0', flags->precision - ft_longnbrlen(l));
		l < 0 ? (ft_putchar('-'), l = -l) : (l += 0);
		ft_putlongnbr(l);
		fill_it(flags, flags->width - size);
	}
	else
	{
		fill_it(flags, flags->width - size);
		flags->o_min && l > 0 ? (ft_putchar('+'), tab[1]++) : (tab[1] += 0);
		if (flags->precision)
			ft_filler('0', flags->precision - ft_longnbrlen(l));
		l < 0 ? (ft_putchar('-'), l = -l) : (l += 0);
		ft_putlongnbr(l);
	}
}

int		print_lint_fill(t_flags *flags, int *tab, long int l)
{
	int	size;

	size = ft_longnbrlen(l);
	if (flags->precision)
		size += (flags->precision - size);
	if (flags->o_plus && l > 0)
		size += 1;
	if (flags->width && size < flags->width)
		print_longint_opt(flags, l, size, tab);
	if (flags->o_plus && l > 0)
		size--;
	return (size);
}

void	print_longierr(int *size)
{
	ft_putstr("-9223372036854775808");
	*size = 20;
}

void	print_long_int(t_flags *flags, va_list list, int *tab)
{
	long int	l;
	int			size;

	l = (long int)va_arg(list, long int);
	if (l > -9223372036854775807)
	{
		if (flags->precision || flags->width)
			size = print_lint_fill(flags, tab, l);
		else
		{
			size = ft_longnbrlen(l);
			if (flags->o_plus)
			{
				ft_putchar('+');
				size++;
			}
			l < 0 ? (ft_putchar('-'), l *= -1, size++) : (l += 0);
			ft_putlongnbr(l);
		}
	}
	else
		print_longierr(&size);
	tab[1] += size;
}

void	arg_is_long_int(t_flags *flags, va_list list, int *tab)
{
	if (!(flags->o_point) || (flags->o_point && flags->precision) || flags->o_sharp)
		print_long_int(flags, list, tab);
}


//----------------------------------------------------------------

void	print_no_size(t_flags *flags, int *tab, int c)
{
	if (c < 0 || (flags->o_plus && c >= 0))
		tab[1] += 1;
	if (flags->o_plus && c >= 0)
		ft_putchar('+');
	ft_putnbr(c);
	tab[1] += ft_nbrlen(c);
}

void	print_width_no_prec(t_flags *flags, int *tab, int c)
{
	int size;

	c >= 0 ? (size = ft_nbrlen(c)) : (size = (ft_nbrlen(c) + 1));
	if (flags->o_plus && c >= 0)
		size += 1;
	if (flags->width > size)
	{
		ft_filler(' ', flags->width - size);
		if (flags->o_plus && c >= 0)
			ft_putchar('+');
		ft_putnbr(c);
		tab[1] += flags->width;
	}
	else
		print_no_size(flags, tab, c);
}

void	print_width_prec_rev(t_flags *flags, int *tab, int c)
{
	int i;
	int size;

	i = 0;
	c < 0 ? ((size = ft_nbrlen(c) + 1), i += 1) : (size = ft_nbrlen(c));
	c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
	if (flags->precision && flags->precision > ft_nbrlen(c))
		ft_filler('0', flags->precision - ft_nbrlen(c));
	ft_putnbr(c);
	if (flags->precision && flags->precision > ft_nbrlen(c))
		ft_filler(' ', flags->width - (flags->precision + i));
	else
		ft_filler(' ', flags->width - size);
	tab[1] += flags->width;
}

void	print_prec_no_width(t_flags *flags, int *tab, int c)
{
	if (flags->precision > ft_nbrlen(c))
	{
		if (flags->o_plus && c >= 0)
		{
			ft_putchar('+');
			tab[1] += 1;
		}
		c < 0 ? (c = -c, ft_putchar('-'), tab[1] += 1) : (c += 0);
		ft_filler('0', flags->precision - ft_nbrlen(c));
		ft_putnbr(c);
		tab[1] += flags->precision;
	}
	else
		print_no_size(flags, tab, c);
}

void	print_width_prec(t_flags *flags, int *tab, int c)
{
	int i;

	i = 0;
	if (c < 0 || (flags->o_plus && c >= 0))
		i += 1;
	if (flags->precision >= flags->width)
		print_prec_no_width(flags, tab, c);
	else
	{
		ft_filler(' ', flags->width - (flags->precision + i));
		if (flags->o_plus && c >= 0)
			ft_putchar('+');
		c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		ft_filler('0', flags->precision - ft_nbrlen(c));
		ft_putnbr(c);
		tab[1] += flags->width;
	}
}

void	check_width_prec(t_flags *flags, int *tab, int c)
{
	int size;

	c >= 0 ? (size = ft_nbrlen(c)) : (size = (ft_nbrlen(c) + 1));
	if (flags->width < size && flags->precision < ft_nbrlen(c))
		print_no_size(flags, tab, c);
	else if (flags->width > size && flags->precision < ft_nbrlen(c))
		print_width_no_prec(flags, tab, c);
	else if (flags->width < size && flags->precision > ft_nbrlen(c))
		print_prec_no_width(flags, tab, c);
	else
		print_width_prec(flags, tab, c);

}

void	print_no_flags(t_flags *flags, int *tab, int c)
{
	if (!flags->width && !flags->precision)
		print_no_size(flags, tab, c);
	else if (flags->width && !flags->precision)
		print_width_no_prec(flags, tab, c);
	else if (!flags->width && flags->precision)
		print_prec_no_width(flags, tab, c);
	else
		check_width_prec(flags, tab, c);
}

void	print_flag_zero(t_flags *flags, int *tab, int c)
{
	int size;

	c >= 0 ? (size = ft_nbrlen(c)) : (size = (ft_nbrlen(c) + 1));
	if (flags->width && flags->width > size && !flags->precision)
	{
		c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		ft_filler('0', flags->width - size);
		ft_putnbr(c);
		tab[1] += flags->width;
	}
	else
		print_no_flags(flags, tab, c);
}

void	print_flag_space(t_flags *flags, int *tab, int c)
{
	int size;

	c >= 0 ? (size = ft_nbrlen(c)) : (size = (ft_nbrlen(c) + 1));
	if (c >= 0 && ((flags->width <= size && !flags->precision) ||
		(flags->precision && (!flags->width || flags->width <= size)) ||
		(flags->width == flags->precision)))
	{
		ft_putchar(' ');
		tab[1] += 1;
		print_no_flags(flags, tab, c);
	}
	else
		print_no_flags(flags, tab, c);
}

void	print_flag_min(t_flags *flags, int *tab, int c, va_list list)
{
	int size;

	c >= 0 ? (size = ft_nbrlen(c)) : (size = (ft_nbrlen(c) + 1));
	if (flags->width && flags->width > size && ((!flags->precision ||
		flags->precision <= ft_nbrlen(c)) || (flags->precision > ft_nbrlen(c) &&
		flags->precision < flags->width)))
		print_width_prec_rev(flags, tab, c);
	else
	{
		flags->o_min = 0;
		arg_is_int_flags(flags, list, tab, c);

	}
}

void	cast_int(int *c, va_list list, t_flags *flags)
{
	if (flags->modif1 == 'h' && flags->modif2 == 'h')
		*c = (signed char)va_arg(list, int);
	else if (flags->modif1 == 'h' && flags->modif2 == '\0')
		*c = (short)va_arg(list, int);
	else
		*c = va_arg(list, int);
}

void	arg_is_int_flags(t_flags *flags, va_list list, int *tab, int c)
{
	if (flags->o_min)
		print_flag_min(flags, tab, c, list);
	else if (flags->o_zero)
		print_flag_zero(flags, tab, c);
	else if (flags->o_space)
		print_flag_space(flags, tab, c);
	else
		print_no_flags(flags, tab, c);
}

void	get_int(t_flags *flags, va_list list, int *tab)
{
	int c;

	cast_int(&c, list, flags);
	arg_is_int_flags(flags, list, tab, c);
}

void	arg_is_int(t_flags *flags, va_list list, int *tab)
{
	if (!(flags->o_point) || (flags->o_point && flags->precision) || flags->o_sharp)
	{
		if (flags->modif1 == 'l' || flags->modif1 == 'j' || flags->modif1 == 'z' ||
			flags->type == 'D')
			arg_is_long_int(flags, list, tab);
		else
			get_int(flags, list, tab);
	}
}


//----------------------------------------------------------------


void	arg_is_wchar(t_flags *flags, va_list list, int *tab)
{
	wchar_t c;

	c = va_arg(list, wchar_t);

	if (!flags->o_min)
	{
		if (flags->width - ft_wcharlen(c) > 0)
			fill_it(flags, flags->width - ft_wcharlen(c));
		tab[1] += ft_putwchar(c);
	}
	else
	{
		tab[1] += ft_putwchar(c);
		if (flags->width - ft_wcharlen(c) > 0)
			fill_it(flags, flags->width - ft_wcharlen(c));
	}
}

void	print_char(t_flags *flags, va_list list, int *tab)
{
	int c;

	c = va_arg(list, int);
	if (flags->width - 1 > 0)
		tab[1] += flags->width - 1;
	if (!flags->o_min)
	{
		if (flags->width - 1 > 0)
			fill_it(flags, flags->width - 1);
		if (c >= 0 && c <= 255)
			ft_putchar((char)c);
	}
	else
	{
		if (c >= 0 && c <= 255)
			ft_putchar((char)c);
		if (flags->width - 1 > 0)
			fill_it(flags, flags->width - 1);
	}
	tab[1] += 1;
}

void	arg_is_char(t_flags *flags, va_list list, int *tab)
{
	if (flags->type == 'C' || flags->modif1 == 'l')
		arg_is_wchar(flags, list, tab);
	else
		print_char(flags, list, tab);
}


//------------------------------------------------------------------------

int		print_wstr_rev(t_flags *flags, wchar_t *str, int size)
{
	if (flags->o_point && flags->precision)
		ft_putwnstr(str, flags->precision);
	else
		str ? ft_putwstr(str) : ft_putstr("(null)");
	if (flags->width > size)
	{
		fill_it(flags, flags->width - size);
		size += flags->width - size;
	}
	return (size);
}

void	print_wstr(t_flags *flags, va_list list, int *tab)
{
	wchar_t	*str;
	int		size;

	size = 0;
	str = va_arg(list, wchar_t*);
	str ? (size = ft_wstrlen(str)) : (size += 0);
	if ((flags->o_point && flags->precision && str))
		size = ft_wnstrlen(str, flags->precision);
	if (!flags->o_min)
	{
		if (flags->width >= size)
		{
			fill_it(flags, flags->width - size);
			size += flags->width - size;
		}
		if (flags->o_point && flags->precision)
			ft_putwnstr(str, flags->precision);
		else
			str ? ft_putwstr(str) : ft_putstr("(null)");
	}
	else
		size = print_wstr_rev(flags, str, size);
	tab[1] += size;
}

void	arg_is_wstr(t_flags *flags, va_list list, int *tab)
{
	if (!(flags->o_point) || (flags->o_point && flags->precision))
		print_wstr(flags, list, tab);
	else if ((flags->o_point && (!(flags->precision)) && flags->width))
	{
		fill_it(flags, flags->width);
		tab[1] += flags->width;
	}
}

//------------------------------------------------------------------------

void	print_string_tool1(t_flags *flags, char *str, int *tab, int size)
{
	int i;

	i = 0;
	if (flags->o_min)
	{
		while (i < flags->precision)
		{
			ft_putchar(str[i]);
			i++;
		}
		fill_it(flags, flags->width - i);
	}
	else
	{
		fill_it(flags, flags->width - flags->precision);
		while(i < flags->precision)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	if (flags->width)
		tab[1] += flags->width;
	else
		tab[1] += size;
}

void	print_string_tool2(t_flags *flags, char *str, int *tab, int size)
{
	int i;

	i = 0;
	if (flags->o_min)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		if (flags->width - size > 0)
			fill_it(flags, flags->width - size);
	}
	else
	{
		if (flags->width - size > 0)
			fill_it(flags, flags->width - size);
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	tab[1] += flags->width;
}


void	print_string(t_flags *flags, va_list list, int *tab)
{
	char	*str;
	int		size;

	str = va_arg(list, char*);
	size = ft_strlen(str);
	if (str)
	{
		if (flags->o_point && (!(flags->precision)))
			fill_it(flags, flags->width);
		else if (flags->o_point && flags->precision)
			print_string_tool1(flags, str, tab, size);
		else if (flags->width)
			print_string_tool2(flags, str, tab, size);
		else
		{
			ft_putstr(str);
			tab[1] += size;
		}
	}
	else
		fill_it(flags, flags->width);
	tab[1] += flags->width;
}

void	arg_is_string(t_flags *flags, va_list list, int *tab)
{
	if ((flags->type == 's' && flags->modif1 == 'l') || flags->type == 'S')
		arg_is_wstr(flags, list, tab);
	else
		print_string(flags, list, tab);
}


//---------------------------------------------------------------------------------------


void arg_is_mod(t_flags *flags, int *tab)
{
	if (flags->type == '%')
	{
		if (!flags->o_min)
		{
			if (flags->width - 1 > 0)
				fill_it(flags, flags->width - 1);
			ft_putchar('%');
			
		}
		else
		{
			ft_putchar('%');
			if (flags->width - 1 > 0)
				fill_it(flags, flags->width - 1);
		}
	}
	if (flags->width)
		tab[1] += flags->width;
	else
		tab[1] += 1;
}


//---------------------------------------------------------------------------------------


void	ft_flagstype(t_flags *flags, va_list list, int *tab)
{
	if (flags->type == '%')
		arg_is_mod(flags, tab);
	if (flags->type == 's' || flags->type == 'S')
		arg_is_string(flags, list, tab);
	if (flags->type == 'c' || flags->type == 'C')
		arg_is_char(flags, list, tab);
	if (flags->type == 'd' || flags->type == 'i' || flags->type == 'D')
		arg_is_int(flags, list, tab);
	/*if (flags->type == 'p')
		arg_is_ptr(flags, list, i);
	if (flags->type == 'x' || flags->type == 'X')
		arg_is_x(flags, list, i);
	if (flags->type == 'o' || flags->type == 'O')
		arg_is_octal(flags, list, i);
	if (flags->type == 'u' || flags->type == 'U')
		arg_is_unsigned(flags, list, i);*/
}



void	ft_type_sort(const char *str, t_flags *flags, va_list list, int *tab)
{
	if (flags->type != '\0')
		ft_flagstype(flags, list, tab);
	else
	{
		if (flags->width - 1 > 0)
		{
			if (!(flags->o_min))
			{
				fill_it(flags, flags->width - 1);
				tab[1] += flags->width - 1;
			}
			else
			{
				ft_putchar(str[tab[0]]);
				tab[1] += flags->width;
				tab[0] += 1;
				fill_it(flags, flags->width - 1);
			}
		}
	}
}

