/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:27:31 by srosu            #+#    #+#              */
/*   Updated: 2026/05/14 11:28:38 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate(t_stack *stack, char c, int *count)
{
	t_list	*tmp;

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
	(*count)++;
	if (c == 'a')
		stack->opp->ra++;
	else
		stack->opp->rb++;
	ft_printf(1, "r%c\n", c);
}
