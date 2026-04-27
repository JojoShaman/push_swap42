/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:27:31 by srosu            #+#    #+#              */
/*   Updated: 2026/04/27 15:27:31 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->head)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = tmp;
	stack->tail = tmp;
	tmp->next = NULL;
	update_position(stack);
}
