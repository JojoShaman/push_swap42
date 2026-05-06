/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   find_biggest.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/28 14:34:25 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 12:25:20 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*find_biggest(t_stack *stack)
{
	t_list	*biggest;
	t_list	*check;

	biggest = stack->head;
	check = stack->head->next;
	while (check)
	{
		if (biggest->value < check->value)
			biggest = check;
		check = check->next;
	}
	return (biggest);
}

t_list	*find_smallest(t_stack *stack)
{
	t_list	*smallest;
	t_list	*check;

	smallest = stack->head;
	check = stack->head->next;
	while (check)
	{
		if (smallest->value > check->value)
			smallest = check;
		check = check->next;
	}
	return (smallest);
}
