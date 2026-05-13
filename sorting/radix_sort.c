/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   radix_sort.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 17:59:48 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 20:30:15 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	radix_sort(t_stack *a, t_stack *b, int *count)
{
	int	bits;
	int	i;
	int	j;
	int	size;

	bits = bits_count(find_biggest(a)->value);
	i = 0;
	size = stack_size(a);
	while (i < bits)
	{
		j = 0;
		while (j < size && a->head)
		{
			if (((a->head->value >> i) & 1) == 0)
				push(b, a, 'b', count);
			else
				rotate(a, 'a', count);
			j++;
		}
		while (b->head)
			push(a, b, 'a', count);
		i++;
	}
}
