/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 23:07:56 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 23:48:43 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	move_both(t_stack *a, t_stack *b, t_list *cheapest, int *count)
{
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, count);
	else
		reverse_rotate_both(a, b, count);
}

static void	move_a(t_stack *a, t_list *cheapest, int *count)
{
	if (cheapest->above_median)
		rotate(a, 'a', count);
	else
		reverse_rotate(a, 'a', count);
}

static void	move_b(t_stack *b, t_list *cheapest, int *count)
{
	if (cheapest->target_node->above_median)
		rotate(b, 'b', count);
	else
		reverse_rotate(b, 'b', count);
}

void	operations(t_stack *a, t_stack *b, t_list *cheapest, int *count)
{
	if (!cheapest->target_node)
	{
		push(b, a, 'b', count);
		return ;
	}
	if (cheapest->current_position && cheapest->target_node->current_position)
		move_both(a, b, cheapest, count);
	else if (cheapest->current_position)
		move_a(a, cheapest, count);
	else if (cheapest->target_node->current_position)
		move_b(b, cheapest, count);
	else
		push(b, a, 'b', count);
}
