CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putaddr_fd.c ft_putchar_fd.c \
		ft_putdec_fd.c ft_puthex_fd.c ft_putstr_fd.c \
		ft_putuint_fd.c ft_strchr.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

