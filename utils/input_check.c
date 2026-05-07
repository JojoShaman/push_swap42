/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   input_check.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/01 18:53:42 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 22:34:11 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

int	check_flag(char *str, t_bool *flags)
{
	if (ft_strcmp(str, "--bench") == 0)
	{
		flags->bench_mode = 1;
		return (1);
	}
	if (ft_strcmp(str, "--adaptive") == 0)
	{
		flags->adaptive = 1;
		return (1);
	}
	return (0);
}

int	error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}
