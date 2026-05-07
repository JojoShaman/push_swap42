/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_size.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/07 20:26:39 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 20:29:50 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

size_t	stack_size(t_stack *stack)
{
	t_list	*track;
	size_t	size;

	track = stack->head;
	size = 0;
	while (track)
	{
		size++;
		track = track->next;
	}
	return (size);
}
