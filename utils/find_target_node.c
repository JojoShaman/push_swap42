/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   find_target_node.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 09:39:44 by srosu            #+#    #+#              */
/*   Updated: 2026/05/11 09:46:46 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <limits.h>

void	find_target_node(t_stack *a, t_stack *b)
{
	t_list	*best;
	t_list	*track_a;
	t_list	*track_b;
	int		best_diff;
	int		diff;

	track_a = a->head;
	while (track_a)
	{
		track_b = b->head;
		best = NULL;
		best_diff = INT_MAX;
		while (track_b)
		{
			diff = 0;
			if (track_b->value < track_a->value)
			{
				diff = track_a->value - track_b->value;
				if (diff < best_diff)
				{
					best_diff = diff;
					best = track_b;
				}
			}
			track_b = track_b->next;
		}
		if (!best)
			best = find_biggest(b);
		track_a->target_node = best;
		track_a = track_a->next;
	}
}
