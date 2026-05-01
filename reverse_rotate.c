/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:27:51 by srosu            #+#    #+#              */
/*   Updated: 2026/05/01 13:01:14 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack, int check)
{
	t_list	*tmp;
	char	c;

	if (check)
		c = 'a';
	else
		c = 'b';
	if (!stack->head)
		return ;
	if (!stack->head->next)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	stack->head->prev = tmp;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->head->prev = NULL;
	ft_printf("rr%c\n", c);
	update_position(stack);
}

void	reverse_rotate_both(t_stack *stack, t_stack *stack2)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack->head || !stack2->head)
		return ;
	tmp = stack->tail;
	tmp2 = stack2->tail;
	stack->tail = stack->tail->prev;
	stack2->tail = stack2->tail->prev;
	stack->tail->next = NULL;
	stack2->tail->next = NULL;
	stack->head->prev = tmp;
	stack2->head->prev = tmp2;
	tmp->next = stack->head;
	tmp2->next = stack2->head;
	stack->head = tmp;
	stack2->head = tmp2;
	stack->head->prev = NULL;
	stack2->head->prev = NULL;
	ft_printf("rrr\n");
	update_position(stack);
	update_position(stack2);
}
