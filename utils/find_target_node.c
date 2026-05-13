/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   find_target_node.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 09:39:44 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 18:23:35 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <limits.h>

static t_list	*find_best(t_list *a_node, t_stack *b)
{
	t_list	*best;
	t_list	*track_b;
	int		best_diff;

	track_b = b->head;
	best = NULL;
	best_diff = INT_MAX;
	while (track_b)
	{
		if ((track_b->value < a_node->value)
			&& ((a_node->value - track_b->value) < best_diff))
		{
			best_diff = a_node->value - track_b->value;
			best = track_b;
		}
		track_b = track_b->next;
	}
	return (best);
}

void	find_target_node(t_stack *a, t_stack *b)
{
	t_list	*best;
	t_list	*track_a;

	track_a = a->head;
	while (track_a)
	{
		best = find_best(track_a, b);
		if (!best)
			best = find_biggest(b);
		track_a->target_node = best;
		track_a = track_a->next;
	}
}
