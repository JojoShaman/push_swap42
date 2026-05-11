/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   node_utils.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:09:35 by srosu            #+#    #+#              */
/*   Updated: 2026/05/11 12:18:08 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	link_node(t_list *node, t_list *node2)
{
	node->next = node2;
	node2->prev = node;
}

t_list	*new_node(int content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = content;
	new->current_position = 0;
	new->chunk_pos = 0;
	new->cost = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_stack *stack)
{
	t_list	*track;
	t_list	*tmp;

	if (!stack->head)
		return ;
	track = stack->head;
	while (track)
	{
		tmp = track->next;
		free(track);
		track = tmp;
	}
	stack->head = NULL;
	stack->tail = NULL;
}
