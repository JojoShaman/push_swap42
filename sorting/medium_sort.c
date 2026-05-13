/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 11:26:40 by srosu            #+#    #+#              */
/*   Updated: 2026/05/14 00:10:37 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	update_info_2(t_stack *a, t_stack *b)
{
	update_position(a);
	update_position(b);
	update_median(a);
	update_median(b);
	if (b->head)
	{
		find_target_node(a, b);
		update_cost(a, b);
	}
}

static void	push_chunk(t_stack *a, t_stack *b, int *count, t_chunk chunk)
{
	t_list	*cheapest;

	while ((int) stack_size(a) != chunk.target_size)
	{
		if (!b->head)
		{
			push(b, a, 'b', count);
			continue ;
		}
		update_info_2(a, b);
		cheapest = find_cheapest(a, chunk.min, chunk.max);
		if (!cheapest)
			break ;
		operations(a, b, cheapest, count);
	}
}

static void	push_all_chunks(t_stack *a, t_stack *b, int *count, int chunk_size)
{
	t_chunk	chunk;
	t_list	*smallest;
	int		size_a;

	while (a->head)
	{
		smallest = find_smallest(a);
		size_a = stack_size(a);
		if (size_a < chunk_size)
			chunk_size = size_a;
		chunk.min = smallest->value;
		chunk.max = smallest->value + (chunk_size - 1);
		chunk.target_size = size_a - chunk_size;
		push_chunk(a, b, count, chunk);
	}
}

static void	empty_b(t_stack *a, t_stack *b, int *count)
{
	t_list	*biggest;

	while (b->head)
	{
		biggest = find_biggest(b);
		if (b->head == biggest)
			push(a, b, 'a', count);
		else if (biggest->above_median)
			rotate(b, 'b', count);
		else
			reverse_rotate(b, 'b', count);
	}
}

void	medium_sort(t_stack *a, t_stack *b, int *count)
{
	int	size_a;
	int	chunk_size;

	size_a = stack_size(a);
	if (size_a <= 50)
		chunk_size = 10;
	else if (size_a <= 100)
		chunk_size = 50;
	else
		chunk_size = 100;
	push_all_chunks(a, b, count, chunk_size);
	empty_b(a, b, count);
}
