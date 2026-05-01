/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   tiny_sort.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:42:40 by srosu            #+#    #+#              */
/*   Updated: 2026/05/01 10:59:29 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort_a(t_stack *stack, int check)
{
	t_list	*biggest;

	biggest = find_biggest(stack);
	if (stack->head->value == biggest->value)
		rotate(stack, check);
	else if (stack->head->next->value == biggest->value)
		reverse_rotate(stack, check);
	if (stack->head->value > stack->head->next->value)
		swap(stack, check);
}

void	tiny_sort_b(t_stack *stack, int check)
{
	t_list	*smallest;

	smallest = find_smallest(stack);
	if (stack->head->value == smallest->value)
		rotate(stack, check);
	else if (stack->head->next->value == smallest->value)
		reverse_rotate(stack, check);
	if (stack->head->value < stack->head->next->value)
		swap(stack, check);
}
