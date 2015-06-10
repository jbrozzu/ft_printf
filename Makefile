#
# HEADER
#

NAME = libftprintf.a

SRC = arg_is_d_maj.c arg_is_d_i.c arg_is_o_omaj_tool2.c arg_is_s_tool.c arg_is_x_xmaj_tool2.c get_info.c tool2_long.c \
arg_is_d_maj_tool1.c arg_is_d_i_tool1.c arg_is_p.c arg_is_u_umaj.c arg_sort.c get_info_tool.c tool2_wchar.c \
arg_is_d_maj_tool2.c arg_is_d_i_tool2.c arg_is_p_tool.c arg_is_u_umaj_tool.c flags_type.c misc.c tool3_long.c \
arg_is_smaj.c arg_is_o_omaj.c arg_is_percent.c arg_is_x_xmaj.c ft_printf.c tool1_long.c \
arg_is_c.c arg_is_o_omaj_tool1.c arg_is_s.c arg_is_x_xmaj_tool1.c tool1_wchar.c \
ft_atoi.c ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_bzero.c ft_isdigit.c ft_strdup.c ft_strcpy.c ft_strcmp.c ft_itoa.c

BIN = arg_is_d_maj.o arg_is_d_i.o arg_is_o_omaj_tool2.o arg_is_s_tool.o arg_is_x_xmaj_tool2.o get_info.o tool2_long.o \
arg_is_d_maj_tool1.o arg_is_d_i_tool1.o arg_is_p.o arg_is_u_umaj.o arg_sort.o get_info_tool.o tool2_wchar.o \
arg_is_d_maj_tool2.o arg_is_d_i_tool2.o arg_is_p_tool.o arg_is_u_umaj_tool.o flags_type.o misc.o tool3_long.o \
arg_is_smaj.o arg_is_o_omaj.o arg_is_percent.o arg_is_x_xmaj.o ft_printf.o tool1_long.o \
arg_is_c.o arg_is_o_omaj_tool1.o arg_is_s.o arg_is_x_xmaj_tool1.o tool1_wchar.o \
ft_atoi.o ft_putchar.o ft_putstr.o ft_strlen.o ft_putnbr.o ft_bzero.o ft_isdigit.o ft_strdup.o ft_strcpy.o ft_strcmp.o ft_itoa.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(BIN)

clean:
	rm -f $(BIN)

fclean:
	rm -f $(NAME) $(BIN)

re: fclean all