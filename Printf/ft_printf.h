/*
HEADER
*/

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <LIMITS.h>
# define MAJHEXA ("0123456789ABCDEF")
# define MINHEXA ("0123456789abcdef")
# define OCTBASE ("0x000000000000")

//# define ULONG_MAX 18446744073709551615

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
	int 		empty_w;
	int 		empty_p;
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
int		absolut_int(int i);
void	init_wchar(unsigned char *f, wchar_t c, int mode);
void	ft_putnchar(unsigned char *f, int size);
char	ft_print_w(unsigned char *f, unsigned int e, wchar_t c);
char	ft_putwchar(wchar_t c);
int		ft_wnstrlen(wchar_t *str, int n);
int		ft_wcharlen(wchar_t c);
int		ft_putwnstr(wchar_t *str, int n);
int		ft_wstrlen(wchar_t *str);
int		ft_putwstr(wchar_t *str);
int		ft_longnbrlen(long int nb);
void	ft_putlongnbr(long int nb);
void	print_plus(t_flags *flags/*, int *tab*/, int c/*, int *size*/);
int		ft_nbrlen(int nbr);
void	ft_putlnbr(unsigned long long int nbr);
int		ft_lnbrlen(unsigned long long int nbr);
int		print_int_fill(t_flags *flags, int *tab, int c);
void	print_int_opt(t_flags *flags, int c, int size, int *tab);
void	arg_is_int_flags(t_flags *flags, va_list list, int *tab, int c);
void	arg_is_long_int_flags(t_flags *flags, va_list list, int *tab, long int c);
int		max_value(t_flags *flags, unsigned long long nb);
void	ft_putnstr(char *str, size_t len);
void	ft_putstrfrom(char *str, size_t len);

# endif