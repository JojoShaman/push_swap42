/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   check_argv.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 17:38:05 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 17:38:18 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_argv(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == '-' && i > 0 && str[i - 1] == '-')
			return (0);
		if (!is_valid(str[i]))
			return (0);
		i++;
	}
	return (1);
}
