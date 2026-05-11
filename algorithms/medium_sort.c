/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 11:26:40 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 16:50:54 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*find_value(t_stack *stack, int nb)
{
	t_list	*track;

	track = stack->head;
	while (track && track->value != nb)
		track = track->next;
	return (track);
}

static void	update_cost(t_stack *stack)
{
	t_list	*track;
	t_list	*target_node;
	int		pos;
	int		t_pos;
	int		median;

	track = stack->head;
	while (track)
	{
		target_node = track->target_node;
		pos = track->current_position;
		t_pos = target_node->current_position;
		if (track->above_median && target_node->above_median)
			track->cost = pos + t_pos;
		else if (!track->above_median && target_node->above_median)
			track->cost = (stack_size(stack) - pos) + t_pos;
		else if (!track->above_median && !target_node->above_median)
			track->cost = (stack_size(stack) - pos) + (stack_size(stack) - t_pos);
	}
}

void	medium_sort(t_stack *a, t_stack *b, int *count)
{
	int		size_a;
	int		chunk_size;
	int		chunk;
	t_list	*track_a;
	t_list	*track_b;
	t_list	*smallest;
	int		biggest;
	t_list	*value;

	size_a = stack_size(a);
	chunk_size = 0;
	chunk = 0;
	track_a = a->head;
	track_b = b->head;
	if (size_a <= 100)
		chunk_size = 100 / 10;
	else
		chunk_size = 100 / 2;
	smallest = find_smallest(a);
	biggest = smallest->value + chunk_size;
	while (1)
	{
		if (track_a->value >= smallest->value && track_a->value >= biggest)
			push(b, a, 'b', count);
		if (chunk == 2)
		{
			sort_three(b, count);
			break ;
		}
	}
	find_target_node(a, b);
	while (a->head)
	{
		if ()
		}
}
