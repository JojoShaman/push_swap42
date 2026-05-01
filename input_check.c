/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   input_check.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/01 18:53:42 by srosu            #+#    #+#              */
/*   Updated: 2026/05/01 19:46:53 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(int c)
{
	return ((c >= '0' && c <= '9') || (c == ' ') || (c = '-'));
}

int	check_argv(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == '-' && str[i - 1] == '-')
			return (0);
		if (!is_valid(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}
