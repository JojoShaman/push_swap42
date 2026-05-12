NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = algorithms/*.c rules/*.c utils/*.c *.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
