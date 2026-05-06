/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:26:42 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 01:41:56 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c, int *count)
{
	t_list	*first_element;
	t_list	*second_element;
	t_list	*third_element;

	third_element = NULL;
	if (stack->head && stack->head->next)
	{
		first_element = stack->head;
		second_element = stack->head->next;
		if (stack->head->next->next)
			third_element = stack->head->next->next;
		second_element->next = first_element;
		second_element->prev = NULL;
		first_element->prev = second_element;
		stack->head = second_element;
		if (third_element)
		{
			first_element->next = third_element;
			third_element->prev = first_element;
		}
		else
			first_element->next = NULL;
	}
	if (c == 'a')
		stack->opp->sa++;
	else
		stack->opp->sb++;
	(*count)++;
	ft_printf("s%c\n", c);
}
