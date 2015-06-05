/*
HEADER
*/

#include "ft_printf.h"

//--------------------------------------------------------------


void	cast_unsigned(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->modif1 == 'j')
		*c = (uintmax_t)va_arg(list, uintmax_t);
	else if (flags->modif1 == 'z')
		*c = (ssize_t)va_arg(list, ssize_t);
	else if (flags->modif1 == 'h' && flags->modif2 == 'h' && flags->type != 'U')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->modif1 == 'h')
		*c = (unsigned short)va_arg(list, int);
	else if (flags->modif1 == 'l' && flags->modif2 == '\0')
		*c = (unsigned long)va_arg(list, unsigned long int);
	else if ((flags->modif1 == 'l' && flags->modif2 == 'l') || flags->type == 'U')
		*c = va_arg(list, unsigned long long int);
	else
		*c = (unsigned int)va_arg(list, unsigned int);
}

void	print_u_no_flags(t_flags *flags, unsigned long long int value, int *tab)
{
	int size;

	size = ft_lnbrlen(value);
	if (flags->width && flags->width > size && (!flags->precision ||
	flags->precision <= size))
	{
		ft_filler(' ', flags->width - size);
		ft_putlnbr(value);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= flags->precision))
	{
		ft_filler('0', flags->precision - size);
		ft_putlnbr(value);
		tab[1] += (flags->precision);
	}
	else if (flags->width && flags->precision && flags->width > flags->precision &&
		flags->precision > size)
	{
		ft_filler(' ', flags->width - flags->precision);
		ft_filler('0', flags->precision - size);
		ft_putlnbr(value);
		tab[1] += flags->width;
	}
	else if (flags->empty_w == 1 && flags->o_point && (flags->empty_p == 0 ||
		(flags->empty_p == 1 && flags->precision == 0))  && value == 0)
		return;
	else
	{
		ft_putlnbr(value);
		tab[1] += size;
	}
}

void	print_u_flag_min(t_flags *flags, unsigned long long int value, int *tab)
{
	int size;

	size = ft_lnbrlen(value);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision < size || flags->width > flags->precision))
	{
		if (flags->precision && flags->precision > size)
			ft_filler('0', flags->precision - size);
			ft_putlnbr(value);
		if (flags->precision && flags->precision > size)
			ft_filler(' ', flags->width - flags->precision);
		else
			ft_filler(' ', flags->width - size);
		tab[1] += flags->width;
	}
	else
		print_u_no_flags(flags, value, tab);
}

void	print_u_flag_zero(t_flags *flags, unsigned long long int value, int *tab)
{	
	int size;

	size = ft_lnbrlen(value);
	if (flags->width && !flags->o_point && !flags->precision && flags->width > size)
	{
		ft_filler('0', flags->width - size);
		ft_putlnbr(value);
		tab[1] += flags->width;
	}
	else
		print_u_no_flags(flags, value, tab);
}

void	get_unsigned_flag(t_flags *flags, unsigned long long int value, int *tab)
{
	if (flags->o_min)
		print_u_flag_min(flags, value, tab);
	else if (flags->o_zero)
		print_u_flag_zero(flags, value, tab);
	else
		print_u_no_flags(flags, value, tab);
}

void	arg_is_unsigned(t_flags *flags, va_list list, int *tab)
{
	unsigned long long int	value;
	
	cast_unsigned(&value, list, flags);
	get_unsigned_flag(flags, value, tab);
}

//-----------------------------------------------------------------------------


void	ft_linttoct(unsigned long long int nb, char *str)
{
	int			i;

	i = 1;
	if (nb > 0)
	{
		while ((nb >> (3 * i)) > 0)
			i++;
		while (nb > 0)
		{
			str[i - 1] = '0' + (nb & (7 << 0));
			i--;
			nb >>= 3;
		}
	}
	else
		str[0] = '0';
}

void	cast_octal(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->modif1 == 'j')
		*c = (uintmax_t)va_arg(list, uintmax_t);
	else if (flags->modif1 == 'z')
		*c = (ssize_t)va_arg(list, ssize_t);
	else if (flags->modif1 == 'h' && flags->modif2 == 'h' && flags->type != 'O')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->modif1 == 'h')
		*c = (unsigned short)va_arg(list, int);
	else if (flags->modif1 == 'l' && flags->modif2 == '\0')
		*c = (unsigned long int)va_arg(list, unsigned long int);
	else if ((flags->modif1 == 'l' && flags->modif2 == 'l') || flags->type == 'O')
		*c = va_arg(list, unsigned long long int);
	else
		*c = (unsigned int)va_arg(list, unsigned int);
}

void	print_oct_no_flags(t_flags *flags, int *tab ,unsigned long long int value, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
	flags->precision <= size))
	{
		ft_filler(' ', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= flags->precision))
	{
		ft_filler('0', flags->precision - size);
		ft_putstr(str);
		tab[1] += (flags->precision);
	}
	else if (flags->width && flags->precision && flags->width > flags->precision &&
		flags->precision > size)
	{
		ft_filler(' ', flags->width - flags->precision);
		ft_filler('0', flags->precision - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->empty_w == 1 && flags->o_point && (flags->empty_p == 0 ||
		(flags->empty_p == 1 && flags->precision == 0))  && value == 0)
		return;
	else
	{
		ft_putstr(str);
		tab[1] += size;
	}
}

void	print_oct_flag_min(t_flags *flags, int *tab ,unsigned long long int value, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision < size || flags->width > flags->precision))
	{
		if (flags->precision && flags->precision > size)
			ft_filler('0', flags->precision - size);
		ft_putstr(str);
		if (flags->precision && flags->precision > size)
			ft_filler(' ', flags->width - flags->precision);
		else
			ft_filler(' ', flags->width - size);
		tab[1] += flags->width;
	}
	else
		print_oct_no_flags(flags, tab, value, str);
}

void 	print_oct_flag_zero(t_flags *flags, int *tab ,unsigned long long int value, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && !flags->o_point && !flags->precision && flags->width > size)
	{
		ft_filler('0', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else
		print_oct_no_flags(flags, tab, value, str);
}

void	print_oct_flag_sharp(t_flags *flags, int *tab ,unsigned long long int value, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->empty_w && flags->o_point && flags->empty_p && value == 0)
	{
		ft_putchar('0');
		tab[1] += 1;
	}
	else if (flags->width && flags->width > (size + 1) && (!flags->precision ||
		flags->precision <= size))
	{
		ft_filler(' ', flags->width - (size + 1));
		ft_putchar('0');
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= (flags->precision + 1)))
	{
		ft_putchar('0');
		ft_filler('0', flags->precision - (size + 1));
		ft_putstr(str);
		tab[1] += (flags->precision);
	}
	else if (flags->width && flags->precision && flags->width > (flags->precision + 1) &&
		flags->precision > size)
	{
		ft_filler(' ', flags->width - (flags->precision));
		ft_putchar('0');
		ft_filler('0', flags->precision - (size + 1));
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else
	{
		if (value != 0)
		{
			ft_putchar('0');
			tab[1] += 1;
		}
		ft_putstr(str);
		tab[1] += size;
	}
}

void	get_oct_flags(t_flags *flags, int *tab, unsigned long long int value, char *str)
{
	if (flags->o_min)
		print_oct_flag_min(flags, tab, value, str);
	else if (flags->o_sharp)
		print_oct_flag_sharp(flags, tab, value, str);
	else if (flags->o_zero)
		print_oct_flag_zero(flags, tab, value, str);
	else
		print_oct_no_flags(flags, tab, value, str);
}

void	arg_is_octal(t_flags *flags, va_list list, int *tab)
{
	unsigned long long int	value;
	char					str[23];
	int						size;

	size = 0;
	ft_bzero(str, 23);
	cast_octal(&value, list, flags);
	
	if ((flags->type == 'O' && value < ULONG_MAX && value != (unsigned long long int)LONG_MIN) ||
	(flags->type == 'o' && value < LONG_MAX))
	{
		ft_linttoct(value, str);
		get_oct_flags(flags, tab, value, str);
	}
	else
	{
		size += limit_max(flags, value);
		tab[1] += size;
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

void	cast_hexa(unsigned long long int *nb, va_list list, t_flags *flags)
{
	if (flags->modif1 == 'h' && flags->modif2 == 'h')
		*nb = (unsigned char)va_arg(list, int);
	else if (flags->modif1 == 'h' && flags->modif2 == '\0')
		*nb = (unsigned short)va_arg(list, int);
	else if (flags->modif1 == 'j' || flags->modif1 == 'z' || (flags->modif1 == 'l' && flags->modif2 == 'l'))
		*nb = va_arg(list, unsigned long long int);
	else if (flags->modif1 == 'l' && flags->modif2 == '\0')
		*nb = va_arg(list, unsigned long int);
	else
		*nb = va_arg(list, unsigned int);
}

void	print_x_flag_sharp(t_flags *flags, int *tab, char *str)
{
	int size;

	size = ft_strlen(str);
	if (!flags->width && flags->o_point && (!flags->precision || flags->precision == 0))
		return;
	else if (flags->width && flags->width > (size + 2) && (!flags->precision ||
		flags->precision <= size))
	{
		ft_filler(' ', flags->width - (size + 2));
		flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= (flags->precision + 2)))
	{
		flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		ft_filler('0', flags->precision - size);
		ft_putstr(str);
		tab[1] += (flags->precision + 2);
	}
	else if (flags->width && flags->precision && flags->width > (flags->precision + 2) &&
		flags->precision > size)
	{
		ft_filler(' ', flags->width - (flags->precision + 2));
		flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		ft_filler('0', flags->precision - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else
	{
		flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		ft_putstr(str);
		tab[1] += size + 2;
	}
}

void	print_x_no_flags(t_flags *flags, int *tab, char *str, unsigned long long int value)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
	flags->precision <= size))
	{
		ft_filler(' ', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > size &&
		(!flags->width || flags->width <= flags->precision))
	{
		ft_filler('0', flags->precision - size);
		ft_putstr(str);
		tab[1] += (flags->precision);
	}
	else if (flags->width && flags->precision && flags->width > flags->precision &&
		flags->precision > size)
	{
		ft_filler(' ', flags->width - flags->precision);
		ft_filler('0', flags->precision - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->empty_w == 1 && flags->o_point && (flags->empty_p == 0 ||
		(flags->empty_p == 1 && flags->precision == 0))  && value == 0)
		return;
	else
	{
		ft_putstr(str);
		tab[1] += size;
	}
}

void	print_x_flag_min(t_flags *flags, int *tab, char *str, unsigned long long int value)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision < size || flags->width > flags->precision))
	{
		if (flags->precision && flags->precision > size)
			ft_filler('0', flags->precision - size);
		ft_putstr(str);
		if (flags->precision && flags->precision > size)
			ft_filler(' ', flags->width - flags->precision);
		else
			ft_filler(' ', flags->width - size);
		tab[1] += flags->width;
	}
	else
		print_x_no_flags(flags, tab, str, value);
}

void 	print_x_flag_zero(t_flags *flags, int *tab, char *str, unsigned long long int value)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && !flags->o_point && !flags->precision && flags->width > size)
	{
		ft_filler('0', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else
		print_x_no_flags(flags, tab, str, value);
}

void	arg_is_x_flags(t_flags *flags, int *tab, char *str, unsigned long long int value)
{
	if (flags->o_sharp && value > 0)
		print_x_flag_sharp(flags, tab, str);
	else if (flags->o_zero)
		print_x_flag_zero(flags, tab, str, value);
	else if (flags->o_min)
		print_x_flag_min(flags, tab, str, value);
	else
		print_x_no_flags(flags, tab, str, value);
}

void	arg_is_x(t_flags *flags, va_list list, int *tab)
{
	unsigned long long int	value;
	char					str[16];

	ft_bzero(str, 16);
	cast_hexa(&value, list, flags);
	flags->type == 'x' ? ft_inttohexa(value, str, MINHEXA) : ft_inttohexa(value, str, MAJHEXA);
	arg_is_x_flags(flags, tab, str, value);
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

void	print_ptr_no_flags(t_flags *flags, int *tab, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision <= (size - 2)))
	{
		ft_filler(' ', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision > (size - 2) &&
		(!flags->width || flags->width <= (flags->precision + 2)))
	{
		ft_putnstr(str, 2);
		ft_filler('0', flags->precision - (size - 2));
		ft_putstrfrom(str, 3);
		tab[1] += (flags->precision + 2);
	}
	else if (flags->width && flags->precision && flags->width > (flags->precision + 2) &&
			flags->precision > size)
	{
		ft_filler(' ', flags->width - (flags->precision + 2));
		ft_putnstr(str, 2);
		ft_filler('0', flags->precision - (size - 2));
		ft_putstrfrom(str, 3);
		tab[1] += flags->width;
	}
	else
	{
		ft_putstr(str);
		tab[1] += size;
	}
}

void 	print_ptr_flag_zero(t_flags *flags, int *tab, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && !flags->precision)
	{
		ft_putnstr(str, 2);
		ft_filler('0', flags->width - size);
		ft_putstrfrom(str, 3);
		tab[1] += flags->width;
	}
	else
		print_ptr_no_flags(flags, tab, str);
}

void	print_ptr_flag_min(t_flags *flags, int *tab, char *str)
{
	int size;

	size = ft_strlen(str);
	if (flags->width && flags->width > size && (!flags->precision ||
		flags->precision < (size - 2) || flags->width > (flags->precision + 2)))
	{
		ft_putnstr(str, 2);
		if (flags->precision && flags->precision > (size - 2))
			ft_filler('0', flags->precision - (size - 2));
		ft_putstrfrom(str, 3);
		if (flags->precision && flags->precision > (size - 2))
			ft_filler(' ', flags->width - (flags->precision + 2));
		else
			ft_filler(' ', flags->width - size);
		tab[1] += flags->width;
	}
	else
		print_ptr_no_flags(flags, tab, str);
}

void	arg_is_ptr_flags(t_flags *flags, int *tab, char *str)
{
	if (flags->o_point && (!flags->precision || flags->precision == 0))
	{
		ft_putstr("0x");
		tab[1] += 2;
	}
	else if (flags->o_zero)
		print_ptr_flag_zero(flags, tab, str);
	else if (flags->o_min)
		print_ptr_flag_min(flags, tab, str);
	else
		print_ptr_no_flags(flags, tab, str);
}


void	arg_is_ptr(t_flags *flags, va_list list, int *tab)
{
	char				*str;
	unsigned long int	pt;

	str = ft_strdup(OCTBASE);
	ft_bzero(str + 2, 12);
	pt = va_arg(list, unsigned long int);
	ft_linttohexa(pt, str, MINHEXA);
	arg_is_ptr_flags(flags, tab, str);
} 


//-------------------------------------------------------------------------



void	print_long_no_size(t_flags *flags, int *tab, long int c)
{
	if (c < 0 || (flags->o_plus && c >= 0))
		tab[1] += 1;
	if (flags->o_plus && c >= 0)
		ft_putchar('+');
	ft_putlongnbr(c);
	tab[1] += ft_longnbrlen(c);
}

void	print_long_width_no_prec(t_flags *flags, int *tab, long int c)
{
	int size;

	c >= 0 ? (size = ft_longnbrlen(c)) : (size = (ft_longnbrlen(c) + 1));
	if (flags->o_plus && c >= 0)
		size += 1;
	if (flags->width > size)
	{
		ft_filler(' ', flags->width - size);
		if (flags->o_plus && c >= 0)
			ft_putchar('+');
		ft_putlongnbr(c);
		tab[1] += flags->width;
	}
	else
		print_long_no_size(flags, tab, c);
}

void	print_long_width_prec_rev(t_flags *flags, int *tab, long int c)
{
	int i;
	int size;

	i = 0;
	c < 0 ? ((size = ft_longnbrlen(c) + 1), i += 1) : (size = ft_longnbrlen(c));
	c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
	if (flags->precision && flags->precision > ft_longnbrlen(c))
		ft_filler('0', flags->precision - ft_longnbrlen(c));
	ft_putlongnbr(c);
	if (flags->precision && flags->precision > ft_longnbrlen(c))
		ft_filler(' ', flags->width - (flags->precision + i));
	else
		ft_filler(' ', flags->width - size);
	tab[1] += flags->width;
}

void	print_long_prec_no_width(t_flags *flags, int *tab, long int c)
{
	if (flags->precision > ft_longnbrlen(c))
	{
		if (flags->o_plus && c >= 0)
		{
			ft_putchar('+');
			tab[1] += 1;
		}
		c < 0 ? (c = -c, ft_putchar('-'), tab[1] += 1) : (c += 0);
		ft_filler('0', flags->precision - ft_longnbrlen(c));
		ft_putlongnbr(c);
		tab[1] += flags->precision;
	}
	else
		print_long_no_size(flags, tab, c);
}

void	print_long_width_prec(t_flags *flags, int *tab, long int c)
{
	int i;

	i = 0;
	if (c < 0 || (flags->o_plus && c >= 0))
		i += 1;
	if (flags->precision >= flags->width)
		print_long_prec_no_width(flags, tab, c);
	else
	{
		ft_filler(' ', flags->width - (flags->precision + i));
		if (flags->o_plus && c >= 0)
			ft_putchar('+');
		c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		ft_filler('0', flags->precision - ft_longnbrlen(c));
		ft_putlongnbr(c);
		tab[1] += flags->width;
	}
}

void	check_long_width_prec(t_flags *flags, int *tab, long int c)
{
	int size;

	c >= 0 ? (size = ft_longnbrlen(c)) : (size = (ft_longnbrlen(c) + 1));
	if (flags->width < size && flags->precision < ft_longnbrlen(c))
		print_long_no_size(flags, tab, c);
	else if (flags->width > size && flags->precision < ft_longnbrlen(c))
		print_long_width_no_prec(flags, tab, c);
	else if (flags->width < size && flags->precision > ft_longnbrlen(c))
		print_long_prec_no_width(flags, tab, c);
	else
		print_long_width_prec(flags, tab, c);
}

void	print_long_no_flags(t_flags *flags, int *tab, long int c)
{
	if (!flags->width && !flags->precision)
		print_long_no_size(flags, tab, c);
	else if (flags->width && !flags->precision)
		print_long_width_no_prec(flags, tab, c);
	else if (!flags->width && flags->precision)
		print_long_prec_no_width(flags, tab, c);
	else
		check_long_width_prec(flags, tab, c);
}

void	print_long_flag_zero(t_flags *flags, int *tab, long int c)
{
	int size;

	c >= 0 ? (size = ft_longnbrlen(c)) : (size = (ft_longnbrlen(c) + 1));
	if (flags->width && flags->width > size && !flags->precision)
	{
		c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		ft_filler('0', flags->width - size);
		ft_putlongnbr(c);
		tab[1] += flags->width;
	}
	else
		print_long_no_flags(flags, tab, c);
}

void	print_long_flag_space(t_flags *flags, int *tab, long int c)
{
	int size;

	c >= 0 ? (size = ft_longnbrlen(c)) : (size = (ft_longnbrlen(c) + 1));
	if (c >= 0 && ((flags->width <= size && !flags->precision) ||
		(flags->precision && (!flags->width || flags->width <= size)) ||
		(flags->width == flags->precision)))
	{
		ft_putchar(' ');
		tab[1] += 1;
		print_long_no_flags(flags, tab, c);
	}
	else
		print_long_no_flags(flags, tab, c);
}

void	print_long_flag_min(t_flags *flags, int *tab, long int c, va_list list)
{
	int size;

	c >= 0 ? (size = ft_longnbrlen(c)) : (size = (ft_longnbrlen(c) + 1));
	if (flags->width && flags->width > size && ((!flags->precision ||
		flags->precision <= ft_longnbrlen(c)) || (flags->precision > ft_longnbrlen(c) &&
		flags->precision < flags->width)))
		print_long_width_prec_rev(flags, tab, c);
	else
	{
		flags->o_min = 0;
		arg_is_long_int_flags(flags, list, tab, c);

	}
}

void	arg_is_long_int_flags(t_flags *flags, va_list list, int *tab, long int c)
{
	if (flags->o_min)
		print_long_flag_min(flags, tab, c, list);
	else if (flags->o_zero)
		print_long_flag_zero(flags, tab, c);
	else if (flags->o_space)
		print_long_flag_space(flags, tab, c);
	else
		print_long_no_flags(flags, tab, c);
}

void	get_long_int(t_flags *flags, va_list list, int *tab)
{
	long long int c;

	if (flags->modif1 == 'j')
		c = (intmax_t)va_arg(list, intmax_t);
	else if (flags->modif1 == 'z')
		c = (size_t)va_arg(list, size_t);
	else if (flags->modif1 == 'l' && flags->modif2 == '\0')
		c = (long)va_arg(list, long int);
	else
		c = va_arg(list, unsigned long long int);
	if (c < -9223372036854775807)
	{
		ft_putstr("-9223372036854775808");
		tab[1] += 20;
		return;
	}
	arg_is_long_int_flags(flags, list, tab, c);
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
		if (c == 0)
		{
			if (flags->o_plus && c >= 0)
			{
				ft_putchar('+');
				ft_filler('0', flags->width - size);
			}
			else if (flags->espace_zero == 1)
				ft_filler('0', flags->width - size);
			else
				ft_filler(' ', flags->width - size);
		}
		else
		{
			ft_filler(' ', flags->width - size);
			if (flags->o_plus && c >= 0)
				ft_putchar('+');
		}
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
		if (flags->width > (flags->precision + i))
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
	if (flags->o_point && (flags->precision == 0 || flags->empty_p == 1) && c == 0)
		return;
	else if (!flags->width && !flags->precision)
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
	if (flags->width && flags->width > size && (flags->empty_p == 1 || flags->precision < 0))
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
	if (c == 0 && flags->width > size)
	{
		ft_putchar(' ');
		tab[1] += 1;
		flags->width -= 1;
		print_no_flags(flags, tab, c);
	}
	else if (c >= 0 && ((flags->width <= size && !flags->precision) ||
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
		if (flags->modif1 == 'l' || flags->modif1 == 'j' || flags->modif1 == 'z' ||
			flags->type == 'D')
			get_long_int(flags, list, tab);
		else
			get_int(flags, list, tab);
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
	if (str == 0)
	{
		ft_putstr("(null)");
		tab[1] += 6;
		return;
	}
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


void	print_str_no_flags(t_flags *flags, int *tab, int size, char *str)
{
	if (flags->o_point && (flags->precision == 0 || flags->empty_p == 1) && !flags->width)
		return;
	else if (flags->width && flags->o_point && !flags->precision)
	{
		ft_filler(' ', flags->width);
		tab[1] += flags->width;
	}
	else if (flags->width && flags->width > size && (!flags->precision || flags->precision >= size))
	{
		ft_filler(' ', flags->width - size);
		ft_putstr(str);
		tab[1] += flags->width;
	}
	else if (flags->precision && flags->precision < size && (!flags->width || flags->width <= flags->precision))
	{
		if (flags->precision < 0)
		{
			ft_putstr(str);
			tab[1] += ft_strlen(str);
		}
		else
		{
			ft_putnstr(str, flags->precision);
			tab[1] += flags->precision;
		}
	}
	else if (flags->precision && flags->precision < size && flags->width && flags->width > flags->precision)
	{
		ft_filler(' ', flags->width - flags->precision);
		ft_putnstr(str, flags->precision);
		tab[1] += flags->width;
	}
	else
	{
		ft_putstr(str);
		tab[1] += size;
	}
}

void	print_str_min(t_flags *flags, int *tab, int size, char *str)
{
	if (flags->width && flags->o_point && !flags->precision)
	{
		ft_filler(' ', flags->width);
		tab[1] += flags->width;
	}
	else if (flags->width && ((!flags->precision && flags->width > size) ||
		(flags->precision && ((flags->precision < size && flags->width >
		flags->precision) || (flags->precision > size && flags->width > size)))))
	{
		if (flags->precision && flags->precision < size)
		{
			ft_putnstr(str, flags->precision);
			ft_filler(' ', flags->width - flags->precision);
			tab[1] += flags->width;
		}
		else
		{
			ft_putstr(str);
			ft_filler(' ', flags->width - size);
			tab[1] += flags->width;
		}
	}
	else
		print_str_no_flags(flags, tab, size, str);
}

void	print_str_zero(t_flags *flags, int *tab, int size, char *str)
{
	if (flags->width && flags->o_point && !flags->precision)
	{
		ft_filler('0', flags->width);
		tab[1] += flags->width;
	}
	else if (flags->width && ((!flags->precision && flags->width > size) ||
		(flags->precision && ((flags->precision < size && flags->width >
		flags->precision) || (flags->precision > size && flags->width > size)))))
	{
		if (flags->precision && flags->precision < size)
		{
			ft_filler('0', flags->width - flags->precision);
			ft_putnstr(str, flags->precision);
		}
		else
		{
			ft_filler('0', flags->width - size);
			ft_putstr(str);
		}
		tab[1] += flags->width;
	}
	else
		print_str_no_flags(flags, tab, size, str);
}

void	print_string(t_flags *flags, va_list list, int *tab)
{
	char *str;
	int size;

	str = va_arg(list, char*);
	if (str == 0 && !(flags->o_point))
	{
		ft_putstr("(null)");
		tab[1] += 6;
		return;
	}
	str == 0 ? (size = 0) : (size = ft_strlen(str));
	if (flags->o_zero)
		print_str_zero(flags, tab, size, str);
	else if (flags->o_min)
		print_str_min(flags, tab, size, str);
	else
		print_str_no_flags(flags, tab, size, str);
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
	else if (flags->type == 's' || flags->type == 'S')
		arg_is_string(flags, list, tab);
	else if (flags->type == 'c' || flags->type == 'C')
		arg_is_char(flags, list, tab);
	else if (flags->type == 'd' || flags->type == 'i' || flags->type == 'D')
		arg_is_int(flags, list, tab);
	else if (flags->type == 'p')
		arg_is_ptr(flags, list, tab);
	else if (flags->type == 'x' || flags->type == 'X')
		arg_is_x(flags, list, tab);
	else if (flags->type == 'o' || flags->type == 'O')
		arg_is_octal(flags, list, tab);
	else if (flags->type == 'u' || flags->type == 'U')
		arg_is_unsigned(flags, list, tab);
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

