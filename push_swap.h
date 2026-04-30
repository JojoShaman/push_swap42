/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:17 by srosu            #+#    #+#              */
/*   Updated: 2026/04/30 21:55:36 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "headers/ft_printf.h"

typedef struct s_list
{
	int				value;
	int				current_position;
	struct s_list	*target_node;
	int				cost;
	int				above_median;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
}	t_stack;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack	tmp;
}	t_data;

t_data	*create_stack_a(const char *str);
t_list	*new_node(int content);
void	link_node(t_list *node, t_list *node2);
void	print_stack(t_stack *stack);
void	swap(t_stack *stack, int check);
void	push(t_stack *dst, t_stack *src, int check);
void	rotate(t_stack *stack, int check);
void	reverse_rotate(t_stack *stack, int check);
void	update_position(t_stack *stack);
void	tiny_sort_a(t_stack *stack, int check);
void	tiny_sort_b(t_stack *stack, int check);
t_list	*find_biggest(t_stack *stack);
t_list	*find_smallest(t_stack *stack);
size_t	ft_strlen(const char *str);
int		count_nb(const char *str);
void	ft_lstclear(t_stack *stack);
char	*ft_strjoin(char *dst, const char *src);
void	b_target(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
void	above_median(t_stack *a, t_stack *b);
void	get_cost(t_stack *stack, t_stack *stack2);
void	update_info(t_stack *a, t_stack *b);

#endif
