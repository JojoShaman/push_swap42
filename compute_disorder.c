/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   compute_disorder.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/01 18:56:26 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 02:35:59 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// float	compute_disorder(t_stack *stack)
// {
// 	int		mistakes;
// 	int		total_pairs;
// 	t_list	*track;
// 	int		i;

// 	mistakes = 0;
// 	total_pairs = 0;
// 	track = stack->head;
// 	while (track && track->next)
// 	{
// 		if (track->value > track->next->value)
// 			mistakes++;
// 		total_pairs++;
// 		track = track->next;
// 	}
// 	return ((float) mistakes / total_pairs);
// }

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
