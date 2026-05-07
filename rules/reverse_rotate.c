/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:27:51 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 16:00:08 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	reverse_rotate(t_stack *stack, char c, int *count)
{
	t_list	*tmp;

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
	(*count)++;
	if (c == 'a')
		stack->opp->rra++;
	else
		stack->opp->rrb++;
	ft_printf(1, "rr%c\n", c);
}

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
