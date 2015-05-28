NAME = libftprintf.a

SRC = ft_printf.c fonction1.c fonction2.c fonction3.c fonction4.c fonction5.c \
fonction6.c fonction7.c libft/ft_atoi.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_strlen.c \
libft/ft_putnbr.c libft/ft_bzero.c libft/ft_isdigit.c libft/ft_strdup.c libft/ft_strcpy.c

BIN = ft_printf.o fonction1.o fonction2.o fonction3.o fonction4.o fonction5.o \
fonction6.o fonction7.o ft_atoi.o ft_putchar.o ft_putstr.o ft_strlen.o ft_bzero.o ft_isdigit.o \
ft_putnbr.o ft_strdup.o ft_strcpy.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(BIN)

clean:
	rm -f $(BIN)

fclean:
	rm -f $(NAME) $(BIN)

re: fclean all