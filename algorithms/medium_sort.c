/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 11:26:40 by srosu            #+#    #+#              */
<<<<<<< HEAD
/*   Updated: 2026/05/13 16:50:54 by srosu           ###   ########.fr        */
=======
/*   Updated: 2026/05/13 01:46:18 by srosu           ###   ########.fr        */
>>>>>>> 435525b (needs some cleaning but medium sort works, also added simple, medium and complex flags)
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*find_cheapest(t_stack *stack, int smallest, int biggest)
{
	t_list	*track;
	t_list	*cheapest;

	track = stack->head;
	cheapest = NULL;
	while (track)
	{
		if (track->value >= smallest && track->value <= biggest)
		{
			if (!cheapest || track->cost < cheapest->cost)
				cheapest = track;
		}
		track = track->next;
	}
	return (cheapest);
}

static void	update_cost(t_stack *stack, t_stack *stack2)
{
	t_list	*track;
	t_list	*target_node;
	int		pos;
	int		t_pos;
	int		size;
	int		t_size;

	track = stack->head;
	size = stack_size(stack);
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
			track->cost = (size - pos) + t_pos;
		else
			track->cost = (size - pos) + (t_size - t_pos);
		// printf("\033[31;1m%d [cost: %d] [above median: %d] [pos: %d]\033[0m ", track->value, track->cost, track->above_median, track->current_position);
		// printf("\033[34;1m%d [cost: %d] [above median: %d] [pos: %d]\033[0m\n", track->target_node->value, track->target_node->cost, track->target_node->above_median, track->target_node->current_position);
		track = track->next;
	}
}

void	operation(t_stack *a, t_stack *b, t_list *cheapest, int *count)
{
	if (!cheapest->current_position && !cheapest->target_node->current_position)
		push(b, a, 'b', count);
	else if ((cheapest->current_position || cheapest->target_node->current_position))
	{
		if (cheapest->target_node->current_position)
		{
			if (cheapest->target_node->above_median)
				rotate(b, 'b', count);
			else
				reverse_rotate(b, 'b', count);
		}
		else if (cheapest->current_position)
		{
			if (cheapest->above_median)
				rotate(a, 'a', count);
			else
				reverse_rotate(a, 'a', count);
		}
	}
	else if (cheapest->current_position && cheapest->target_node->current_position)
	{
		if (cheapest->above_median && cheapest->target_node->above_median)
			rotate_both(a, b, count);
		else
			reverse_rotate_both(a, b, count);
	}
}

void	update_info(t_stack *a, t_stack *b)
{
	update_position(a);
	update_position(b);
	update_median(a);
	update_median(b);
	find_target_node(a, b);
	update_cost(a, b);
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
	t_list	*biggest_b;
	t_list	*value;
	t_list	*cheapest;

	size_a = stack_size(a);
	chunk_size = 0;
	chunk = 0;
	track_a = a->head;
	track_b = b->head;
	if (size_a <= 50)
		chunk_size = 10;
	else if (size_a <= 100)
		chunk_size = 50;
	else
		chunk_size = 100;
	smallest = find_smallest(a);
	biggest = smallest->value + (chunk_size - 1);
	while (chunk < 3)
	{
		while (a->head->value >= smallest->value && a->head->value <= biggest)
		{
			if (chunk == 3)
				break ;
			push(b, a, 'b', count);
			chunk++;
		}
		rotate(a, 'a', count);
	}
	sort_three(b, 'b', count);
	while (a->head && stack_size(a) != size_a - chunk_size)
	{
		update_info(a, b);
		cheapest = find_cheapest(a, smallest->value, biggest);
		operation(a, b, cheapest, count);
	}
	while (a->head)
	{
		smallest = find_smallest(a);
		size_a = stack_size(a);
		if (size_a < chunk_size)
			chunk_size = size_a;
		biggest = smallest->value + (chunk_size - 1);
		while (stack_size(a) != size_a - chunk_size)
		{
			update_info(a, b);
			cheapest = find_cheapest(a, smallest->value, biggest);
			operation(a, b, cheapest, count);
		}
	}
	while (b->head)
	{
		biggest_b = find_biggest(b);
		if (b->head == biggest_b)
			push(a, b, 'a', count);
		else
		{
			if (biggest_b->above_median)
				rotate(b, 'b', count);
			else
				reverse_rotate(b, 'b', count);
		}
	}
}
