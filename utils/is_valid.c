/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:37:37 by srosu             #+#    #+#             */
/*   Updated: 2026/05/18 18:31:25 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_valid(int c)
{
	return ((c >= '0' && c <= '9') || (c == ' ') || (c == '-'));
}

static int	is_argv_contain_number(int argc, char **argv, t_bool *flags)
{
	int	i;
	int	j;
	int	count_number;

	i = 1;
	while (i < argc)
	{
		if (check_flag(argv[i], flags))
		{
			i++;
			continue ;
		}
		count_number = 0;
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				count_number++;
			j++;
		}
		if (count_number == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_argv_is_valid(int argc, char **argv, t_bool *flags)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (check_flag(argv[i], flags))
		{
			i++;
			continue ;
		}
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && argv[i][j + 1] &&
				argv[i][j + 1] == '-')
				return (0);
			if (!is_valid(argv[i][j++]))
				return (0);
		}
		i++;
	}
	return (is_argv_contain_number(argc, argv, flags));
}
