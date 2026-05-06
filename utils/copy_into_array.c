/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   copy_into_array.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 19:24:48 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 12:25:20 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	*copy_into_array(t_stack *a)
{
	int		*tab;
	int		i;
	t_list	*track;

	i = 0;
	track = a->head;
	tab = malloc((a->tail->current_position + 1) * (sizeof(*tab)));
	if (!tab)
		return (NULL);
	while (track)
	{
		tab[i] = track->value;
		i++;
		track = track->next;
	}
	return (tab);
}
