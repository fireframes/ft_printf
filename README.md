# ft_printf

https://cdn.intra.42.fr/pdf/pdf/125481/en.subject.pdf


This is a Makefile, a file used by the make build automation tool to compile and build projects. It defines a set of rules for creating the output files from the source files.

Here's a breakdown of the Makefile:

CC = cc: This sets the variable CC to cc, which is the C compiler. This variable is used to compile the source files.

CFLAGS = -Wall -Wextra -Werror: This sets the variable CFLAGS to -Wall -Wextra -Werror, which are flags for the compiler. -Wall, -Wextra and -Werror enable all warning messages, extra warning messages, and treat warnings as errors, respectively.

SRCS = ft_printf.c ft_putaddr_fd.c ft_putchar_fd.c ft_putdec_fd.c ft_puthex_fd.c ft_putstr_fd.c ft_putuint_fd.c ft_strchr.c: This sets the variable SRCS to a list of C source files.

OBJS = $(SRCS:.c=.o): This sets the variable OBJS to the value of SRCS, but with .c replaced by .o. This effectively generates a list of object files from the list of source files.

NAME = libftprintf.a: This sets the variable NAME to libftprintf.a, which is the name of the output file (a static library in this case).

all: $(NAME): This is a rule that says "to build all, build $(NAME)". all is a conventional target that builds everything in the Makefile.

$(NAME): $(OBJS): This is a rule that says "to build $(NAME), build $(OBJS)". It also specifies a recipe (ar rcs $(NAME) $?) to create $(NAME) from $(OBJS). $? is a special variable that holds the names of the prerequisites that are newer than the target.

%.o: %.c: This is a pattern rule that says "to build a file ending in .o, build a corresponding file ending in .c". It also specifies a recipe ($(CC) $(CFLAGS) -c $?) to create the .o file from the .c file.

clean:, fclean: clean, and re: fclean all are rules for cleaning up the project. clean removes the object files, fclean removes the object files and the library, and re rebuilds everything from scratch.

.PHONY: all clean fclean re: This tells make that all, clean, fclean, and re are not files, but phony targets. This is done because if there were a file named all, clean, fclean, or re, make would not execute these targets.
