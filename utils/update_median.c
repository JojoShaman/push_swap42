/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   update_median.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 08:47:07 by srosu            #+#    #+#              */
/*   Updated: 2026/05/11 09:58:06 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stddef.h>

void	update_median(t_stack *stack)
{
	size_t	size;
	t_list	*track;

	size = stack_size(stack);
	track = stack->head;
	while (track)
	{
		if (track->current_position < size / 2)
			track->above_median = 1;
		else
			track->above_median = 0;
		track = track->next;
	}
}
