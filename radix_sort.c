/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   radix_sort.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 17:59:48 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 00:58:45 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b, int *count)
{
	int	bits;
	int	i;
	int	j;
	int	size;

	bits = bits_count(find_biggest(a)->value);
	i = 0;
	size = find_biggest(a)->value + 1;
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
			push(a, b, 'b', count);
		i++;
	}
}
