/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate_both.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/14 11:28:50 by srosu            #+#    #+#              */
/*   Updated: 2026/05/14 11:28:50 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	rotate_both_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->head;
	if (stack->head->next == NULL)
		return ;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = tmp;
	tmp->prev = stack->tail;
	stack->tail = tmp;
	tmp->next = NULL;
}

void	rotate_both(t_stack *stack, t_stack *stack2, int *count)
{
	if (!stack->head || !stack2->head)
		return ;
	rotate_both_stack(stack);
	rotate_both_stack(stack2);
	stack->opp->rr++;
	(*count)++;
	ft_printf(1, "rr\n");
}
