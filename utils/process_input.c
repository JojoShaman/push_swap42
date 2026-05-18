/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 22:29:32 by srosu             #+#    #+#             */
/*   Updated: 2026/05/18 10:18:06 by mbuchet          ###   ########.fr       */
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

static void	process_str_join(char **s1, char *s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = ft_strjoin(tmp, s2);
	free(tmp);
}

char	*process_argv(int argc, char **argv, t_bool *flags)
{
	int		i;
	char	*str;

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
			process_str_join(&str, argv[i]);
			if (i != argc + (count_flag(argv, flags) - 1))
				process_str_join(&str, " ");
		}
		i++;
	}
	return (str);
}
