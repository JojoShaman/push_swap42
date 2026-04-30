/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:27:31 by srosu            #+#    #+#              */
/*   Updated: 2026/04/30 17:06:21 by srosu           ###   ########.fr        */
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
	ft_printf("r%c ", c);
	update_position(stack);
}
