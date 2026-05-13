/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_three.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 12:14:38 by srosu            #+#    #+#              */
/*   Updated: 2026/05/12 23:39:22 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_stack *stack, char c, int *count)
{
	t_list	*biggest;
	t_list	*smallest;

	biggest = find_biggest(stack);
	smallest = find_smallest(stack);
	if (c == 'a')
	{
		if (stack->head->value == biggest->value)
			rotate(stack, c, count);
		else if (stack->head->next->value == biggest->value)
			reverse_rotate(stack, c, count);
		if (stack->head->value > stack->head->next->value)
			swap(stack, c, count);
	}
	else
	{
		if (stack->head->value == smallest->value)
			rotate(stack, c, count);
		else if (stack->head->next->value == smallest->value)
			reverse_rotate(stack, c, count);
		if (stack->head->value < stack->head->next->value)
			swap(stack, c, count);
	}
}
