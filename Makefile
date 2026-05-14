NAME = push_swap
PRINTF_LIB = printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iheaders
PUSH_SWAP_SRCS 	=	sorting/medium_sort.c \
					sorting/radix_sort.c \
					sorting/simple_sort.c \
					sorting/sort_array.c \
					sorting/sort_three.c \
					rules/push.c \
					rules/reverse_rotate_both.c \
					rules/reverse_rotate.c \
					rules/rotate_both.c \
					rules/rotate.c \
					rules/swap.c \
					utils/adapt_strategy.c \
					utils/bench.c \
					utils/bits_count.c \
					utils/check_argv.c \
					utils/compute_disorder.c \
					utils/copy_into_array.c \
					utils/count_nb.c \
					utils/find_biggest.c \
					utils/find_cheapest.c \
					utils/find_target_node.c \
					utils/flag_input.c \
					utils/ft_atoi.c \
					utils/ft_atol.c \
					utils/ft_memset.c \
					utils/ft_strcmp.c \
					utils/ft_strjoin.c \
					utils/ft_strlen.c \
					utils/ft_substr.c \
					utils/is_valid.c \
					utils/node_utils.c \
					utils/operations.c \
					utils/parsing.c \
					utils/process_input.c \
					utils/replace_value.c \
					utils/return_error.c \
					utils/run_sort.c \
					utils/stack_size.c \
					utils/update_cost.c \
					utils/update_median.c \
					utils/update_position.c \
					utils/word_len.c \
					main.c

PRINTF_SRCS 	=  	printf/ft_printf.c \
					printf/ft_putchar_fd.c \
					printf/ft_putnbr_base.c \
					printf/ft_putnbr_fd.c \
					printf/ft_putstr_fd.c \
					printf/handler.c


PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

all: $(PRINTF_LIB) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF_LIB): $(PRINTF_OBJS)
	ar rcs $(PRINTF_LIB) $(PRINTF_OBJS)

$(NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(PUSH_SWAP_OBJS) -Lprintf -lftprintf -o $(NAME)

clean:
	rm -f $(PUSH_SWAP_OBJS) $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME) $(PRINTF_LIB)

re: fclean all

.PHONY: clean fclean re all
