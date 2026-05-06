/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:26:42 by srosu             #+#    #+#             */
/*   Updated: 2026/05/06 04:41:52 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_list	*first_element;
	t_list	*second_element;
	t_list	*third_element;

	first_element = stack->head;
	second_element = stack->head->next;
	third_element = NULL;
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

void	swap(t_stack *stack, char c, int *count)
{
	if (stack->head && stack->head->next)
		swap_stack(stack);
	if (c == 'a')
		stack->opp->sa++;
	else
		stack->opp->sb++;
	(*count)++;
	ft_printf("s%c\n", c);
}
