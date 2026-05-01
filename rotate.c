/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:27:31 by srosu            #+#    #+#              */
/*   Updated: 2026/05/01 12:35:23 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, int check)
{
	t_list	*tmp;
	char	c;

	if (check)
		c = 'a';
	else
		c = 'b';
	if (!stack->head)
		return ;
	tmp = stack->head;
	if (stack->head->next)
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->tail->next = tmp;
		tmp->prev = stack->tail;
		stack->tail = tmp;
		tmp->next = NULL;
	}
	ft_printf("r%c\n", c);
	update_position(stack);
}

void	rotate_both(t_stack *stack, t_stack *stack2)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack->head || !stack2->head)
		return ;
	tmp = stack->head;
	tmp2 = stack2->head;
	if (stack->head->next)
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->tail->next = tmp;
		tmp->prev = stack->tail;
		stack->tail = tmp;
		tmp->next = NULL;
	}
	if (stack2->head->next)
	{
		stack2->head = stack2->head->next;
		stack2->head->prev = NULL;
		stack2->tail->next = tmp2;
		tmp2->prev = stack2->tail;
		stack2->tail = tmp2;
		tmp2->next = NULL;
	}
	ft_printf("rr\n");
	update_position(stack);
	update_position(stack2);
}
