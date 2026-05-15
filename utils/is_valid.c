/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:37:37 by srosu             #+#    #+#             */
/*   Updated: 2026/05/15 03:53:38 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_valid(int c)
{
	return ((c >= '0' && c <= '9') || (c == ' ') || (c == '-'));
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
	return (1);
}
