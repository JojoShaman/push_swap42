/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:09:35 by srosu             #+#    #+#             */
/*   Updated: 2026/05/14 21:43:37 by mbuchet          ###   ########.fr       */
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
	new->target_node = NULL;
	new->above_median = 0;
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

int	check_contain_number_in_pre_stack(char *str, int start, int number)
{
	char	*sub_str;
	long	number_l;

	number_l = number;
	while (str[start])
	{
		while (str[start] == ' ')
			start++;
		if (!str[start])
			break ;
		sub_str = ft_substr(str, start, word_len(str, start, ' '));
		if (!sub_str)
			return (1);
		if (ft_atol(sub_str) == number_l)
		{
			free(sub_str);
			return (1);
		}
		free(sub_str);
		start += word_len(str, start, ' ');
	}
	return (0);
}
