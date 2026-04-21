/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rules.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:18 by srosu            #+#    #+#              */
/*   Updated: 2026/04/21 14:13:11 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
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
}

void	push(t_data *stack)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*tail_a;
	t_list	*tail_b;

	head_a = stack->stack_a.head;
	head_b = stack->stack_b.head;
}
