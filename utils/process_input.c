/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   process_input.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/07 22:29:32 by srosu            #+#    #+#              */
/*   Updated: 2026/05/15 16:22:26 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_int_limits_args(char *str)
{
	int		start;
	char	*sub_str;
	long	last_number;

	start = 0;
	while (str[start])
	{
		while (str[start] == ' ')
			start++;
		if (!str[start])
			break ;
		sub_str = ft_substr(str, start, word_len(str, start, ' '));
		if (!sub_str)
			return (0);
		last_number = ft_atol(sub_str);
		if (last_number < INT_MIN || last_number > INT_MAX)
		{
			free(sub_str);
			return (0);
		}
		free(sub_str);
		start += word_len(str, start, ' ');
	}
	return (1);
}

int	check_duplicate_args(char *str)
{
	int		start;
	char	*sub_str;
	long	last_number;

	start = 0;
	while (str[start])
	{
		while (str[start] == ' ')
			start++;
		if (!str[start])
			break ;
		sub_str = ft_substr(str, start, word_len(str, start, ' '));
		if (!sub_str)
			return (0);
		last_number = ft_atoi(sub_str);
		start += word_len(str, start, ' ');
		if (check_contain_number_in_pre_stack(str, start, last_number))
		{
			free(sub_str);
			return (0);
		}
		free(sub_str);
	}
	return (1);
}

char	*process_argv(int argc, char **argv, t_bool *flags)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = NULL;
	while (i < (argc + count_flag(argv, flags)))
	{
		if (!check_flag(argv[i], flags))
		{
			if (!check_argv(argv[i]))
			{
				free(str);
				return (NULL);
			}
			tmp = str;
			str = ft_strjoin(tmp, argv[i]);
			free(tmp);
			if (i != argc + (count_flag(argv, flags) - 1))
			{
				tmp = str;
				str = ft_strjoin(tmp, " ");
				free(tmp);
			}
		}
		i++;
	}
	return (str);
}
