/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:56:26 by srosu             #+#    #+#             */
/*   Updated: 2026/05/07 17:58:54 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

static float	count_disorder(t_stack *stack, size_t stack_size, t_list *node)
{
	int		total_pairs;
	int		mistakes;
	t_list	*next_node;

	total_pairs = stack_size * (stack_size - 1) / 2;
	while (node)
	{
		next_node = node->next;
		while (next_node)
		{
			if (node->value > next_node->value)
				mistakes++;
			next_node = next_node->next;
		}
		node = node->next;
	}
	return ((float) mistakes / total_pairs);
}

float	compute_disorder(t_stack *stack)
{
	size_t	stack_size;
	t_list	*node;

	stack_size = 0;
	node = stack->head;
	while (node)
	{
		stack_size++;
		node = node->next;
	}
	if (stack_size < 2)
		return (0.0f);
	return (count_disorder(stack, stack_size, node));
}
