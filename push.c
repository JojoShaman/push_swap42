/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 15:26:22 by srosu            #+#    #+#              */
/*   Updated: 2026/05/01 12:31:36 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src, int check)
{
	t_list	*tmp;
	char	c;

	if (check)
		c = 'a';
	else
		c = 'b';
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
	ft_printf("p%c\n", c);
	update_position(dst);
	update_position(src);
}
