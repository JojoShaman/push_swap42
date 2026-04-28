/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/28 16:51:32 by srosu            #+#    #+#              */
/*   Updated: 2026/04/28 19:47:53 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	above_median(t_stack *stack)
{
	int		lst_size;
	t_list	*track;

	lst_size = stack->tail->current_position;
	track = stack->head;
	while (track)
	{
		if (track->current_position < lst_size / 2)
			track->above_median = 1;
		else
			track->above_median = 0;
		track = track->next;
	}
}

void	b_target(t_stack *a, t_stack *b)
{
	t_list	*a_track;
	t_list	*b_track;
	t_list	*best;
	int		diff;
	int		best_diff;

	a_track = a->head;
	while (a_track)
	{
		best = NULL;
		best_diff = INT_MAX;
		b_track = b->head;
		while (b_track)
		{
			if (b_track->value < a_track->value)
			{
				diff = a_track->value - b_track->value;
				if (diff < best_diff)
				{
					best_diff = diff;
					best = b_track;
				}
			}
			b_track = b_track->next;
		}
		if (!best)
			best = find_biggest(b);
		a_track->target_node = best;
		a_track = a_track->next;
	}
}

void	get_cost(t_stack *stack)
{
	//
}

void	sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->tail->current_position;
	j = 1;
	while (i >= 3)
	{
		push(b, a);
		if (j == 3)
		{
			tiny_sort_b(b);
			break ;
		}
		j++;
		i--;
	}
}
