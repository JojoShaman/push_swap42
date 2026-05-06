/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:09:39 by srosu             #+#    #+#             */
/*   Updated: 2026/05/06 17:02:23 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static int	word_len(char const *s, int start, char c)
{
	int	wl;

	wl = 0;
	while (s[start + wl] != c && s[start + wl] != '\0')
		wl++;
	return (wl);
}

static int	create_node(t_data *stack, char *substr, int i)
{
	t_list	*node;

	node = new_node(ft_atoi(substr));
	if (!node)
	{
		ft_lstclear(&stack->stack_a);
		free(substr);
		free(stack);
		return (0);
	}
	node->current_position = i;
	if (i == 0)
	{
		stack->stack_a.head = node;
		stack->stack_a.tail = node;
	}
	else if (i > 0)
	{
		link_node(stack->stack_a.tail, node);
		stack->stack_a.tail = node;
	}
	return (1);
}

static t_data	*construct_stack_a(const char *str, t_data *stack)
{
	int 	start;
	char	*substr;
	int		i;
	int		temp;

	start = 0;
	i = 0;
	while (str[start])
	{
		while (str[start] == ' ')
			start++;
		if (!str[start])
			break ;
		substr = ft_substr(str, start, word_len(str, start, ' '));
		temp = create_node(stack, substr, i++);
		if (temp == 0)
			return (NULL);
		free(substr);
		start += word_len(str, start, ' ');
	}
	return (stack);
}

t_data	*create_stack_a(const char *str)
{
	t_data	*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->stack_a.head = NULL;
	stack->stack_a.tail = NULL;
	stack->stack_b.head = NULL;
	stack->stack_b.tail = NULL;
	memset(&stack->opp, 0, sizeof(stack->opp));
	stack->stack_a.opp = &stack->opp;
	stack->stack_b.opp = &stack->opp;
	return (construct_stack_a(str, stack));
}
