/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   compute_disorder.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/01 18:56:26 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 00:20:58 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack)
{
	int		n;
	int		total_pairs;
	int		mistakes;
	t_list	*i;
	t_list	*j;

	n = 0;
	i = stack->head;
	while (i)
	{
		n++;
		i = i->next;
	}
	if (n < 2)
		return (0.0f);
	total_pairs = n * (n - 1) / 2;
	mistakes = 0;
	i = stack->head;
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
