NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRCS = ft_printf.c type_is.c ft_putchar_fd.c ft_putnbr_base.c ft_putstr_fd.c ft_putnbr_fd.c ft_putnbr_unsigned_fd.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^
%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@
clean: 
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re