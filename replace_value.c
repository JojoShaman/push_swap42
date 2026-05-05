/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   replace_value.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 23:24:20 by srosu            #+#    #+#              */
/*   Updated: 2026/05/05 23:24:20 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_value(int *tab, t_stack *a, int size)
{
	int		i;
	t_list	*track;

	i = 0;
	while (i < size)
	{
		track = a->head;
		while (track)
		{
			if (tab[i] == track->value)
			{
				track->value = i;
				break ;
			}
			track = track->next;
		}
		i++;
	}
}
