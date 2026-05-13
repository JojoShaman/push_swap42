/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/06 00:41:07 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 17:36:11 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	sort_four(t_stack *a, t_stack *b, int *count)
{
	int	smallest;

	smallest = find_smallest(a)->value;
	while (a->head->value != smallest)
		rotate(a, 'a', count);
	push(b, a, 'b', count);
	(*count)++;
	sort_three(a, 'a', count);
	push(a, b, 'a', count);
}

static void	sort_five(t_stack *a, t_stack *b, int *count)
{
	int	smallest;
	int	i;

	i = 0;
	while (i < 2)
	{
		smallest = find_smallest(a)->value;
		while (a->head->value != smallest)
			rotate(a, 'a', count);
		push(b, a, 'b', count);
		i++;
	}
	if (b->head->value < b->head->next->value)
		swap(b, 'b', count);
	sort_three(a, 'a', count);
	while (i--)
		push(a, b, 'a', count);
}

static void	update_info(t_stack *stack)
{
	update_position(stack);
	update_median(stack);
}

static void	small_sort(t_stack *a, t_stack *b, int *count)
{
	int	size;

	size = stack_size(a);
	if (size == 2)
	{
		if (a->head->value > a->head->next->value)
			swap(a, 'a', count);
		return ;
	}
	if (size == 3)
		return (sort_three(a, 'a', count));
	else if (size == 4)
		return (sort_four(a, b, count));
	else if (size == 5)
		return (sort_five(a, b, count));
}

void	simple_sort(t_stack *a, t_stack *b, int *count)
{
	t_list	*smallest;
	int		size;

	size = stack_size(a);
	if (size <= 5)
		return (small_sort(a, b, count));
	while (a->head)
	{
		smallest = find_smallest(a);
		update_info(a);
		while (a->head->value != smallest->value)
		{
			update_info(a);
			smallest = find_smallest(a);
			if (smallest->above_median)
				rotate(a, 'a', count);
			else
				reverse_rotate(a, 'a', count);
		}
		push(b, a, 'b', count);
	}
	while (b->head)
		push(a, b, 'a', count);
}
