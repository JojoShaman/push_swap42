/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:27:31 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 00:09:37 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate(t_stack *stack, char c, int *count)
{
	t_list	*tmp;
	t_opp	opp;

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
	if (!stack->bool->bench_mode)
		ft_printf(1, "r%c\n", c);
}

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
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack->head || !stack2->head)
		return ;
	rotate_both_stack(stack);
	rotate_both_stack(stack2);
	stack->opp->rr++;
	(*count)++;
	if (!stack->bool->bench_mode)
		ft_printf(1, "rr\n");
}
