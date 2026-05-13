NAME = push_swap
PRINTF_LIB = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -Iheaders
SRCS = $(wildcard sorting/*.c rules/*.c utils/*.c) parsing.c push_swap.c
OBJS = $(SRCS:.c=.o)
PRINTF_SRCS = $(wildcard printf/*.c)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

all: $(PRINTF_LIB) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF_LIB): $(PRINTF_OBJS)
	ar rcs $(PRINTF_LIB) $(PRINTF_OBJS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L. -lftprintf -o $(NAME)

clean:
	rm -f $(OBJS) $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME) $(PRINTF_LIB)

re: fclean all

.PHONY: clean fclean re all
