/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   flag_input.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/01 18:53:42 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 18:03:06 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_flag(char *str, t_bool *flags)
{
	if (ft_strcmp(str, "--bench") == 0)
		return (flags->bench_mode = 1);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (flags->adaptive = 1);
	else if (ft_strcmp(str, "--simple") == 0)
		return (flags->simple = 1);
	else if (ft_strcmp(str, "--medium") == 0)
		return (flags->medium = 1);
	else if (ft_strcmp(str, "--complex") == 0)
		return (flags->complex = 1);
	return (0);
}
