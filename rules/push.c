/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:26:22 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 16:03:08 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push(t_stack *dst, t_stack *src, char c, int *count)
{
	t_list	*tmp;

	if (!src->head)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	tmp->next = dst->head;
	if (dst->head)
		dst->head->prev = tmp;
	dst->head = tmp;
	dst->head->prev = NULL;
	if (!dst->tail)
		dst->tail = tmp;
	(*count)++;
	if (c == 'a')
		dst->opp->pa++;
	else
		dst->opp->pb++;
	ft_printf(1, "p%c\n", c);
}
