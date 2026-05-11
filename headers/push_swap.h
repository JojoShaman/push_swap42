/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:17 by srosu            #+#    #+#              */
/*   Updated: 2026/05/11 10:08:29 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_list
{
	int				value;
	int				current_position;
	int				above_median;
	struct s_list	*prev;
	struct s_list	*next;
	struct s_list	*target_node;
}	t_list;

typedef struct s_bool
{
	int	bench_mode;
	int	adaptive;
}	t_bool;

typedef struct s_strat
{
	char	*strategy;
}	t_strat;

typedef struct s_opp
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_opp;

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
	t_opp	*opp;
	t_bool	*bool;
	t_strat	*s_ptr;
}	t_stack;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_opp	opp;
	t_bool	flags;
	t_strat	big_o;
}	t_data;

/* stack init */
t_data	*create_stack_a(const char *str);
t_list	*new_node(int content);
void	link_node(t_list *node, t_list *node2);
int		count_nb(const char *str);

/* stack handlers */
void	run_sort(t_stack *a, t_stack *b, t_data *stacks);
void	adapt_strategy(t_data *s, float disorder, int *count);

/* rules */
void	swap(t_stack *stack, char c, int *count);
void	push(t_stack *dst, t_stack *src, char c, int *count);
void	rotate(t_stack *stack, char c, int *count);
void	rotate_both(t_stack *stack, t_stack *stack2, int *count);
void	reverse_rotate(t_stack *stack, char c, int *count);
void	reverse_rotate_both(t_stack *stack, t_stack *stack2, int *count);

/* algoritms */
void	radix_sort(t_stack *a, t_stack *b, int *count);
void	simple_sort(t_stack *a, t_stack *b, int *count);
void	sort_array(int *tab, int size);
void    medium_sort(t_stack *a, t_stack *b, int *count);

/* algoritm utils */
t_list	*find_biggest(t_stack *stack);
t_list	*find_smallest(t_stack *stack);
int		bits_count(int max);
float	compute_disorder(t_stack *stack);
int		*copy_into_array(t_stack *a);
void	replace_value(int *tab, t_stack *a, int size);
void	print_bench(t_data stack, int count, int whole, int frac);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);
size_t	stack_size(t_stack *stack);
void	update_median(t_stack *stack);
void	update_position(t_stack *stack);
void	find_target_node(t_stack *a, t_stack *b);

/* process input */
int		is_valid(int c);
int		check_argv(char *str);
int		error(int fd);
int		check_flag(char *str, t_bool *flags);
int		parse_single_arg(char **argv, int i, t_data **stack);
char	*process_argv(int argc, char **argv, t_bool *flags);

/* libft */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstclear(t_stack *stack);
char	*ft_strjoin(char *dst, const char *src);
int		word_len(char const *s, int start, char c);

#endif
