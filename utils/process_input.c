/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 22:29:32 by srosu             #+#    #+#             */
/*   Updated: 2026/05/12 21:41:49 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	parse_single_arg(char **argv, int i, t_data **stack)
{
	if (!check_argv(argv[i]))
		return (error(2));
	if (count_nb(argv[i]) > 1)
		*stack = create_stack_a(argv[i]);
	else
		return (error(2));
	return (-1);
}

int	check_duplicate_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		j_index;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (argv[j] == NULL)
				break ;
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
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
	while (i < argc)
	{
		if (!check_flag(argv[i], flags))
		{
			if (!check_argv(argv[i]))
				return (free(str), NULL);
			tmp = str;
			str = ft_strjoin(tmp, argv[i]);
			free(tmp);
			if (i != argc - 1)
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
