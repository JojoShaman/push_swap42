NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SDIR = c_files
ODIR = o_files
SRCS = ${SDIR}/ft_printf.c ${SDIR}/handler.c ${SDIR}/ft_putchar_fd.c ${SDIR}/ft_putnbr_base.c ${SDIR}/ft_putstr_fd.c ${SDIR}/ft_putnbr_fd.c
OBJS = $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,${SRCS})

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^
${ODIR}/%.o: ${SDIR}/%.c ../headers/ft_printf.h
	mkdir -p ${ODIR}
	${CC} ${CFLAGS} -c $< -o $@ -I../headers
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re