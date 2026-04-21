/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:17 by srosu            #+#    #+#              */
/*   Updated: 2026/04/21 14:13:13 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

typedef struct s_list
{
	int				value;
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
}	t_data;

t_data	*create_stack_a(const char *str);
t_list	*new_node(int content);
void	link_node(t_list *node, t_list *node2);
void	print_stack(t_stack *stack);
void	swap(t_stack *stack);

#endif
