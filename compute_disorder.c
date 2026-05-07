/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   compute_disorder.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/01 18:56:26 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 20:34:09 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

static float	count_disorder(t_stack *stack, size_t stack_size, t_list *node)
{
	int		total_pairs;
	int		mistakes;
	t_list	*next_node;

	total_pairs = stack_size * (stack_size - 1) / 2;
	mistakes = 0;
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
	size_t	size;

	size = stack_size(stack);
	if (size < 2)
		return (0.0f);
	return (count_disorder(stack, size, stack->head));
}
