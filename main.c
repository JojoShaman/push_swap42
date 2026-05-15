/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:10:15 by srosu             #+#    #+#             */
/*   Updated: 2026/05/15 03:54:05 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static int	is_valid_soustraction(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (!str[i + 1])
				return (0);
			if (str[i + 1] && (str[i + 1] == ' ' || str[i + 1] == '-'))
				return (0);
			i++;
			while (str[i] && str[i] >= '0' && str[i] <= '9')
				i++;
			if (str[i] && str[i] == '-')
				return (0);
		}
		i++;
	}
	return (1);
}

int	count_flag(char **argv, t_bool *flags)
{
	int	i;
	int	count_flag;

	i = 1;
	count_flag = 0;
	while (argv[i])
	{
		if (check_flag(argv[i], flags))
			count_flag++;
		i++;
	}
	return (count_flag);
}

int	init_and_run(int argc, char **argv, t_data **stack, t_bool *flags)
{
	char	*str;

	if (is_argv_is_valid(argc, argv, flags) == 0)
		return (error(2));
	str = process_argv(argc, argv, flags);
	if (argc > 2 && !is_valid_soustraction(str))
		return (error_with_free_str(2, str));
	if (!str)
		return (error_with_free_str(2, str));
	if (!check_int_limits_args(str))
		return (error_with_free_str(2, str));
	if (!check_duplicate_args(str))
		return (error_with_free_str(2, str));
	*stack = create_stack_a(str);
	free(str);
	if (!*stack)
		return (1);
	count_flag(argv, flags);
	(*stack)->flags = *flags;
	run_sort(&(*stack)->stack_a, &(*stack)->stack_b, *stack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*stack;
	int		temp_int;
	t_bool	flags;
	int		i;

	i = 1;
	ft_memset(&flags, 0, sizeof(t_bool));
	if (argc < 2)
		return (error(2));
	argc -= count_flag(argv, &flags);
	while (check_flag(argv[i], &flags))
		i++;
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 1 && argv[1][0] == '-')
			return (error(2));
		temp_int = parse_single_arg(argv, i, &stack);
		if (temp_int != -1)
			return (temp_int);
	}
	return (init_and_run(argc, argv, &stack, &flags));
}
