/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   tiny_sort.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:42:40 by srosu            #+#    #+#              */
/*   Updated: 2026/04/27 18:46:00 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack *stack)
{
	if (find_biggest(stack->head))
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	else if (find_biggest(stack->head->next))
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
