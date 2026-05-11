/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   update_position.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 08:43:08 by srosu            #+#    #+#              */
/*   Updated: 2026/05/11 09:30:57 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	update_position(t_stack *stack)
{
	int		i;
	t_list	*track;

	i = 0;
	track = stack->head;
	while (track)
	{
		track->current_position = i;
		track = track->next;
		i++;
	}
}
