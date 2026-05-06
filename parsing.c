/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:09:39 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 01:38:22 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_len(char const *s, int start, char c)
{
	int	wl;

	wl = 0;
	while (s[start + wl] != c && s[start + wl] != '\0')
		wl++;
	return (wl);
}

t_data	*create_stack_a(const char *str)
{
	int		i;
	int		start;
	t_data	*stack;
	t_list	*node;
	char	*substr;

	i = 0;
	start = 0;
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
	while (str[start])
	{
		while (str[start] == ' ')
			start++;
		if (!str[start])
			break ;
		substr = ft_substr(str, start, word_len(str, start, ' '));
		node = new_node(ft_atoi(substr));
		if (!node)
		{
			ft_lstclear(&stack->stack_a);
			free(substr);
			free(stack);
			return (NULL);
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
		free(substr);
		start += word_len(str, start, ' ');
		i++;
	}
	return (stack);
}
