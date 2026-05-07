/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:56:26 by srosu             #+#    #+#             */
/*   Updated: 2026/05/07 17:38:36 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

static float	compute_disorder2(t_stack *stack, int n, t_list *i)
{
	int		mistakes;
	int		total_pairs;
	t_list	*j;

	total_pairs = n * (n - 1) / 2;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((float) mistakes / total_pairs);
}

float	compute_disorder(t_stack *stack)
{
	int		n;
	t_list	*i;

	n = 0;
	i = stack->head;
	while (i)
	{
		n++;
		i = i->next;
	}
	if (n < 2)
		return (0.0f);
	return (compute_disorder2(stack, n, i));
}
