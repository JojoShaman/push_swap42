/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   find_cheapest.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 23:13:16 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 23:13:17 by srosu           ###   ########.fr        */
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
