/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_stack.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:09:40 by srosu            #+#    #+#              */
/*   Updated: 2026/04/28 18:28:24 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, int check)
{
	t_list	*track;
	int		target;

	track = stack->head;
	if (check)
	{
		while (track)
		{
			ft_printf("[%d] %d [target: %d]\n", track->current_position, track->value, track->target_node->value);
			track = track->next;
		}
	}
	else
	{
		while (track)
		{
			ft_printf("[%d] %d\n", track->current_position, track->value);
			track = track->next;
		}
	}
}
