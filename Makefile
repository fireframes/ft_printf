CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell ls *.c)

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

