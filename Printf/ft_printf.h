/*
HEADER
*/

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	char		o_min;
	char		o_plus;
	char		o_zero;
	char		o_sharp;
	char		o_space;
	char		o_point;
	char		modif1;
	char		modif2;
	int			width;
	int			precision;
	int			size;
	char		type;
}				t_flags;


int 	ft_printf(const char *format, ...);
int		check_str_ex(const char *str);
int		check_conv(const char *format);
void	init_flags(const char *str, t_flags *flags, int *i);
void	ft_arg_sort(const char *str, va_list list, int *tab);
int		get_flags(const char *str, va_list list);
void	check_flag(const char *str, t_flags *flags, int *tab);
char	*ft_get_next_valor(const char *str, int *tab, char *result);
void	check_width(const char *str, t_flags *flags, int *tab);
void	check_prec(const char *str, t_flags *flags, int *tab);
void	check_modif(const char *str, t_flags *flags, int *tab);
void	check_type(const char *str, t_flags *flags, int *i);
void	ft_type_sort(const char *str, t_flags *flags, va_list list, int *i);
void	ft_filler(char c, size_t len);
void	fill_it(t_flags *flags, int size);


# endif