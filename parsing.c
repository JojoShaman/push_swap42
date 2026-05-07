/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:09:39 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 17:32:24 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static int	create_node(t_stack *stack_a, char *substr, int i)
{
	t_list	*node;

	node = new_node(ft_atoi(substr));
	if (node == NULL)
	{
		ft_lstclear(stack_a);
		free(substr);
		free(stack_a);
		return (0);
	}
	node->current_position = i;
	if (i == 0)
	{
		stack_a->head = node;
		stack_a->tail = node;
	}
	else if (i > 0)
	{
		link_node(stack_a->tail, node);
		stack_a->tail = node;
	}
	return (1);
}

static t_data	*construct_stack_a(const char *str, t_data *stack_data)
{
	int		start;
	int		index;
	char	*sub_str;

	start = 0;
	index = 0;
	while (str[start])
	{
		while (str[start] == ' ')
			start++;
		if (!str[start])
			break ;
		sub_str = ft_substr(str, start, word_len(str, start, ' '));
		if (create_node(&stack_data->stack_a, sub_str, index++) == 0)
			return (NULL);
		free(sub_str);
		start += word_len(str, start, ' ');
	}
	return (stack_data);
}

static void	init_stack(t_data *stack_data, t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->bool = &stack_data->flags;
	stack->opp = &stack_data->opp;
}

t_data	*create_stack_a(const char *str)
{
	t_data	*stack_data;

	stack_data = malloc(sizeof(*stack_data));
	if (stack_data == NULL)
		return (NULL);
	ft_memset(&stack_data->opp, 0, sizeof(stack_data->opp));
	ft_memset(&stack_data->flags, 0, sizeof(stack_data->flags));
	stack_data->big_o.strategy = "";
	init_stack(stack_data, &stack_data->stack_a);
	return (construct_stack_a(str, stack_data));
}
