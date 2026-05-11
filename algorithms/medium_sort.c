/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 05:50:14 by mbuchet           #+#    #+#             */
/*   Updated: 2026/05/10 23:07:06 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	ft_sqrt(int nb)
{
	int	index;

	index = 0;
	if (nb <= 0)
		return (0);
	while (index <= nb)
	{
		if (index * index == nb)
			return (index);
		index++;
	}
	return (ft_sqrt(nb - 1));
}

void	medium_sort(t_stack *a, t_stack *b, int *count)
{
	int		a_size;
	int		chunk_size;
	int		index;
	int		chunk_index;
	int		biggest;

	a_size = stack_size(a);
	chunk_size = ft_sqrt(a_size);
	index = 0;
	while (chunk_size != 0)
	{
		chunk_index = 0;
		while (chunk_index < chunk_size)
		{
			push(b, a, 'b', count);
			chunk_index++;
		}
		a_size = a_size - chunk_index;
		chunk_size = ft_sqrt(a_size);
		while (b->head)
		{
			biggest = find_biggest(b)->value;
			while (b->head->value != biggest)
				rotate(b, 'b', count);
			push(a, b, 'a', count);
		}
		index++;
	}
}
