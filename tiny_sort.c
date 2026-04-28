/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   tiny_sort.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:42:40 by srosu            #+#    #+#              */
/*   Updated: 2026/04/28 19:29:31 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort_a(t_stack *stack)
{
	t_list	*biggest;

	biggest = find_biggest(stack);
	if (stack->head->value == biggest->value)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	else if (stack->head->next->value == biggest->value)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	if (stack->head->value > stack->head->next->value)
	{
		swap(stack);
		ft_printf("sa\n");
	}
}

void	tiny_sort_b(t_stack *stack)
{
	t_list	*smallest;

	smallest = find_smallest(stack);
	if (stack->head->value == smallest->value)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	else if (stack->head->next->value == smallest->value)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	if (stack->head->value < stack->head->next->value)
	{
		swap(stack);
		ft_printf("sa\n");
	}
}
