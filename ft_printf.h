/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:41:19 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/06/10 21:36:02 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <LIMITS.h>
# define MAJHEXA ("0123456789ABCDEF")
# define MINHEXA ("0123456789abcdef")
# define OCTBASE ("0x000000000000")

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
	int			empty_w;
	int			empty_p;
	int			espace_zero;
}				t_flags;

int				ft_printf(const char *format, ...);
int				check_str_ex(const char *str);
int				check_conv(const char *format);
void			ft_arg_sort(const char *str, va_list list, int *tab);
int				get_flags(const char *str, va_list list);
void			check_flag(const char *str, t_flags *flags, int *tab);
void			check_width(const char *str, t_flags *flags, int *tab,
	va_list list);
void			check_prec(const char *str, t_flags *flags, int *tab,
	va_list list);
void			check_modif(const char *str, t_flags *flags, int *tab);
void			check_type(const char *str, t_flags *flags, int *tab);
void			init_flags(const char *str, t_flags *flags, int *tab,
	va_list list);
char			*ft_get_next_valor(const char *str, int *tab, char *result);
void			ft_wildcard(t_flags *flags, va_list list, int *tab);
void			ft_flagstype(t_flags *flags, va_list list, int *tab);
void			ft_type_sort(const char *str, t_flags *flags, va_list list,
	int *tab);
int				ft_putwstr(wchar_t *str);
char			ft_print_w(unsigned char *f, unsigned int e, wchar_t c);
int				ft_wnstrlen(wchar_t *str, int n);
int				ft_wstrlen(wchar_t *str);
int				ft_wcharlen(wchar_t c);
int				max_unsigned_long(t_flags *flags);
int				max_long(t_flags *flags);
int				max_unsigned_octal_long(t_flags *flags);
int				limit_max(t_flags *flags, unsigned long long nb);
int				ft_longnbrlen(long int nb);
void			ft_putlongnbr(long int nb);
void			print_plus(t_flags *flags, int c);
int				ft_nbrlen(int nbr);
void			ft_putlnbr(unsigned long long int nbr);
int				ft_lnbrlen(unsigned long long int nbr);
void			init_wchar(unsigned char *f, wchar_t c, int mode);
void			ft_putnchar(unsigned char *f, int size);
char			ft_putwchar(wchar_t c);
int				ft_putwnstr(wchar_t *str, int n);
void			ft_filler(char c, size_t len);
void			fill_it(t_flags *flags, int size);
int				absolut_int(int i);
void			ft_putnstr(char *str, size_t len);
void			ft_putstrfrom(char *str, size_t len);
void			arg_is_wchar(t_flags *flags, va_list list, int *tab);
void			print_char(t_flags *flags, va_list list, int *tab);
void			arg_is_char(t_flags *flags, va_list list, int *tab);
void			print_no_size(t_flags *flags, int *tab, int c);
void			tool_print_width(t_flags *flags, int c, int size);
void			print_width_no_prec(t_flags *flags, int *tab, int c);
void			print_width_prec_rev(t_flags *flags, int *tab, int c);
void			print_prec_no_width(t_flags *flags, int *tab, int c);
void			print_width_prec(t_flags *flags, int *tab, int c);
void			check_width_prec(t_flags *flags, int *tab, int c);
void			print_no_flags(t_flags *flags, int *tab, int c);
void			print_flag_zero(t_flags *flags, int *tab, int c);
void			print_flag_space(t_flags *flags, int *tab, int c);
void			print_flag_min(t_flags *flags, int *tab, int c, va_list list);
void			cast_int(int *c, va_list list, t_flags *flags);
void			arg_is_int_flags(t_flags *flags, va_list list, int *tab, int c);
void			get_int(t_flags *flags, va_list list, int *tab);
void			arg_is_int(t_flags *flags, va_list list, int *tab);
void			print_long_no_size(t_flags *flags, int *tab, long int c);
void			print_long_width_no_prec(t_flags *flags, int *tab, long int c);
void			print_long_width_prec_rev(t_flags *flags, int *tab, long int c);
void			print_long_prec_no_width(t_flags *flags, int *tab, long int c);
void			print_long_width_prec(t_flags *flags, int *tab, long int c);
void			check_long_width_prec(t_flags *flags, int *tab, long int c);
void			print_long_no_flags(t_flags *flags, int *tab, long int c);
void			print_long_flag_zero(t_flags *flags, int *tab, long int c);
void			print_long_flag_space(t_flags *flags, int *tab, long int c);
void			print_long_flag_min(t_flags *flags, int *tab, long int c,
	va_list list);
void			arg_is_long_int_flags(t_flags *flags, va_list list, int *tab,
	long int c);
void			get_long_int(t_flags *flags, va_list list, int *tab);
void			tool1_oct_no_flags(t_flags *flags, int size, char *str,
	int *tab);
void			tool2_oct_no_flags(t_flags *flags, int size, char *str,
	int *tab);
void			print_oct_no_flags(t_flags *flags, int *tab,
	unsigned long long int value, char *str);
void			print_oct_flag_min(t_flags *flags, int *tab,
	unsigned long long int value, char *str);
void			print_oct_flag_zero(t_flags *flags, int *tab,
	unsigned long long int value, char *str);
void			tool1_oct_sharp(t_flags *flags, int size, char *str, int *tab);
void			tool2_oct_sharp(t_flags *flags, int size, char *str, int *tab);
void			tool3_oct_sharp(t_flags *flags, int size, char *str, int *tab);
void			tool4_oct_sharp(unsigned long long int value, int *tab,
	char *str, int size);
void			print_oct_flag_sharp(t_flags *flags, int *tab,
	unsigned long long int value, char *str);
void			ft_linttoct(unsigned long long int nb, char *str);
void			cast_octal(unsigned long long int *c, va_list list,
	t_flags *flags);
void			get_oct_flags(t_flags *flags, int *tab,
	unsigned long long int value, char *str);
void			arg_is_octal(t_flags *flags, va_list list, int *tab);
void			tool1_ptr_no_flags(t_flags *flags, char *str, int size,
	int *tab);
void			tool2_ptr_no_flags(t_flags *flags, char *str, int size,
	int *tab);
void			print_ptr_no_flags(t_flags *flags, int *tab, char *str);
void			print_ptr_flag_zero(t_flags *flags, int *tab, char *str);
void			print_ptr_flag_min(t_flags *flags, int *tab, char *str);
void			ft_linttohexa(unsigned long int nb, char *str, char *hex);
void			arg_is_ptr_flags(t_flags *flags, int *tab, char *str);
void			arg_is_ptr(t_flags *flags, va_list list, int *tab);
void			arg_is_mod(t_flags *flags, int *tab);
int				print_wstr_rev(t_flags *flags, wchar_t *str, int size);
void			tool_wstr(t_flags *flags, int *size, wchar_t *str);
void			print_wstr(t_flags *flags, va_list list, int *tab);
void			arg_is_wstr(t_flags *flags, va_list list, int *tab);
void			tool_string1(t_flags *flags, char *str, int *tab, int size);
void			tool_string2(t_flags *flags, char *str, int *tab);
void			tool_string3(t_flags *flags, char *str, int *tab);
void			print_str_no_flags(t_flags *flags, int *tab, int size,
	char *str);
void			print_str_min(t_flags *flags, int *tab, int size, char *str);
void			print_str_zero(t_flags *flags, int *tab, int size, char *str);
void			print_string(t_flags *flags, va_list list, int *tab);
void			arg_is_string(t_flags *flags, va_list list, int *tab);
void			tool1_u_no_flags(t_flags *flags, unsigned long long int value,
	int *tab, int size);
void			tool2_u_no_flags(t_flags *flags, unsigned long long int value,
	int *tab, int size);
void			tool3_u_no_flags(t_flags *flags, unsigned long long int value,
	int *tab, int size);
void			print_u_no_flags(t_flags *flags, unsigned long long int value,
	int *tab);
void			cast_unsigned(unsigned long long int *c, va_list list,
	t_flags *flags);
void			print_u_flag_min(t_flags *flags, unsigned long long int value,
	int *tab);
void			print_u_flag_zero(t_flags *flags, unsigned long long int value,
	int *tab);
void			get_unsigned_flag(t_flags *flags, unsigned long long int value,
	int *tab);
void			arg_is_unsigned(t_flags *flags, va_list list, int *tab);
void			tool1_x_shap(t_flags *flags, int size, char *str, int *tab);
void			tool2_x_shap(t_flags *flags, int size, char *str, int *tab);
void			tool3_x_shap(t_flags *flags, int size, char *str, int *tab);
void			print_x_flag_sharp(t_flags *flags, int *tab, char *str);
void			tool1_x_no_flags(t_flags *flags, int size, char *str, int *tab);
void			tool2_x_no_flags(t_flags *flags, int size, char *str, int *tab);
void			print_x_no_flags(t_flags *flags, int *tab, char *str,
	unsigned long long int value);
void			print_x_flag_min(t_flags *flags, int *tab, char *str,
	unsigned long long int value);
void			print_x_flag_zero(t_flags *flags, int *tab, char *str,
	unsigned long long int value);
void			ft_inttohexa(unsigned long long int nb, char *str, char *hex);
void			cast_hexa(unsigned long long int *nb, va_list list,
	t_flags *flags);
void			arg_is_x_flags(t_flags *flags, int *tab, char *str,
	unsigned long long int value);
void			arg_is_x(t_flags *flags, va_list list, int *tab);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putstr(char const *str);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);

#endif
