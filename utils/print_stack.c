/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_stack.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:09:40 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 12:25:20 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_list	*track;
	int		target;

	track = stack->head;
	while (track)
	{
		ft_printf("\n%d", track->value);
		track = track->next;
	}
}
