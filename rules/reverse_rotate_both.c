/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate_both.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/14 11:28:05 by srosu            #+#    #+#              */
/*   Updated: 2026/05/14 11:28:05 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	reverse_rotate_both(t_stack *stack, t_stack *stack2, int *count)
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
	(*count)++;
	stack->opp->rrr++;
	ft_printf(1, "rrr\n");
}
