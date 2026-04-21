/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:09:39 by srosu            #+#    #+#              */
/*   Updated: 2026/04/21 14:13:19 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	substring = malloc((len + 1) * sizeof(*substring));
	if (!substring)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

static int	count_nb(const char *str)
{
	int	i;
	int	nb;
	int	in_nb;

	i = 0;
	nb = 0;
	in_nb = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !in_nb)
		{
			in_nb = 1;
			nb++;
		}
		if (str[i] == ' ' && in_nb)
			in_nb = 0;
		i++;
	}
	return (nb);
}

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
	while (str[start])
	{
		while (str[start] == ' ')
			start++;
		if (!str[start])
			break ;
		substr = ft_substr(str, start, word_len(str, start, ' '));
		node = new_node(ft_atoi(substr));
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
