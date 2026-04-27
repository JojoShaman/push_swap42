/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   update_position.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:25:51 by srosu            #+#    #+#              */
/*   Updated: 2026/04/27 15:25:51 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack *stack)
{
	t_list	*current;
	int		i;

	current = stack->head;
	i = 0;
	while (current)
	{
		current->current_position = i;
		current = current->next;
		i++;
	}
}
