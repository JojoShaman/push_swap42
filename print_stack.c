/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_stack.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:09:40 by srosu            #+#    #+#              */
/*   Updated: 2026/04/30 17:07:40 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_list	*track;
	int		target;

	track = stack->head;
	while (track)
	{
		ft_printf("\n[%d] %d [target: %d] [above_median %d] [cost %d]", track->current_position, track->value, track->target_node->value, track->above_median, track->cost);
		track = track->next;
	}
}
