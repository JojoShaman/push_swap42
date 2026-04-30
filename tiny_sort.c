/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   tiny_sort.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:42:40 by srosu            #+#    #+#              */
/*   Updated: 2026/04/30 17:04:40 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort_a(t_stack *stack)
{
	t_list	*biggest;

	biggest = find_biggest(stack);
	if (stack->head->value == biggest->value)
		rotate(stack, 1);
	else if (stack->head->next->value == biggest->value)
		reverse_rotate(stack, 1);
	if (stack->head->value > stack->head->next->value)
		swap(stack, 1);
}

void	tiny_sort_b(t_stack *stack)
{
	t_list	*smallest;

	smallest = find_smallest(stack);
	if (stack->head->value == smallest->value)
		rotate(stack, 0);
	else if (stack->head->next->value == smallest->value)
		reverse_rotate(stack, 0);
	if (stack->head->value < stack->head->next->value)
		swap(stack, 0);
}
