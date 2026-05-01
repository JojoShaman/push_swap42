/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   compute_disorder.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/01 18:56:26 by srosu            #+#    #+#              */
/*   Updated: 2026/05/01 18:56:31 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*track;
	int		i;

	mistakes = 0;
	total_pairs = 0;
	track = stack->head;
	while (track)
	{
		if (track->next && track->value > track->next->value)
			mistakes += 1;
		track = track->next;
		total_pairs += 1;
	}
	printf("total_p: %d, mistakes: %d\n", total_pairs, mistakes);
	return ((float) mistakes / total_pairs);
}
