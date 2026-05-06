/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/06 00:41:07 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 12:29:20 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	sort_three(t_stack *a, int *count)
{
	t_list	*biggest;

	biggest = find_biggest(a);
	if (a->head->value == biggest->value)
		rotate(a, 'a', count);
	else if (a->head->next->value == biggest->value)
		reverse_rotate(a, 'a', count);
	if (a->head->value > a->head->next->value)
		swap(a, 'a', count);
}

static void	sort_four(t_stack *a, t_stack *b, int *count)
{
	int	smallest;

	smallest = find_smallest(a)->value;
	while (a->head->value != smallest)
		rotate(a, 'a', count);
	push(b, a, 'b', count);
	(*count)++;
	sort_three(a, count);
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
	sort_three(a, count);
	while (i--)
		push(a, b, 'a', count);
}

void	simple_sort(t_stack *a, t_stack *b, int *count)
{
	int	smallest;
	int	size;

	size = a->tail->current_position + 1;
	if (size == 2)
	{
		if (a->head->value > a->head->next->value)
			swap(a, 'a', count);
		return ;
	}
	if (size == 3)
		return (sort_three(a, count));
	else if (size == 4)
		return (sort_four(a, b, count));
	else if (size == 5)
		return (sort_five(a, b, count));
	while (a->head)
	{
		smallest = find_smallest(a)->value;
		while (a->head->value != smallest)
			rotate(a, 'a', count);
		push(b, a, 'b', count);
	}
	while (b->head)
		push(a, b, 'a', count);
}
