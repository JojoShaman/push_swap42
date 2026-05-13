/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   update_cost.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 23:13:43 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 23:52:05 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	update_cost(t_stack *stack, t_stack *stack2)
{
	t_list	*track;
	t_list	*target_node;
	int		pos;
	int		t_pos;
	int		t_size;

	track = stack->head;
	t_size = stack_size(stack2);
	while (track)
	{
		target_node = track->target_node;
		pos = track->current_position;
		t_pos = target_node->current_position;
		if (track->above_median && target_node->above_median)
			track->cost = pos + t_pos;
		else if (track->above_median && !target_node->above_median)
			track->cost = pos + (t_size - t_pos);
		else if (!track->above_median && target_node->above_median)
			track->cost = (stack_size(stack) - pos) + t_pos;
		else
			track->cost = (stack_size(stack) - pos) + (t_size - t_pos);
		track = track->next;
	}
}
