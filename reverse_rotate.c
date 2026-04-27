/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:27:51 by srosu            #+#    #+#              */
/*   Updated: 2026/04/27 15:27:51 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->head)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->head->prev = NULL;
	update_position(stack);
}
