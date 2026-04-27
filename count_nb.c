/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   count_nb.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 20:15:54 by srosu            #+#    #+#              */
/*   Updated: 2026/04/27 20:15:54 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nb(const char *str)
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
