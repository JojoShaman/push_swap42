/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_three.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/11 12:14:38 by srosu            #+#    #+#              */
/*   Updated: 2026/05/11 12:14:58 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_stack *a, int *count)
{
	t_list	*biggest;

	biggest = find_biggest(a);
	if (a->head->value == biggest->value)
		rotate(a, 'a', count);
	else if (a->head->next->value == biggest->value)
		reverse_rotate(a, 'a', count);
	if (a->head->value > a->head->next->value)
		swap(a, 'a', count);
}
