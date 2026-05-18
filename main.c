/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:15 by srosu            #+#    #+#              */
/*   Updated: 2026/05/18 23:12:07 by srosu           ###   ########.fr        */
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
			if (i > 0 && str[i - 1] >= '0' && str[i - 1] <= '9')
				return (0);
			if (!str[i + 1])
				return (0);
			if (str[i + 1] == ' ' || str[i + 1] == '-')
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
	if (!str)
		return (error_with_free_str(2, str));
	if (!is_valid_soustraction(str))
		return (error_with_free_str(2, str));
	if (!check_int_limits_args(str))
		return (error_with_free_str(2, str));
	if (!check_duplicate_args(str))
		return (error_with_free_str(2, str));
	*stack = create_stack_a(str);
	free(str);
	if (!*stack)
		return (1);
	(*stack)->flags = *flags;
	run_sort(&(*stack)->stack_a, &(*stack)->stack_b, *stack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*stack;
	t_bool	flags;
	int		i;

	i = 1;
	ft_memset(&flags, 0, sizeof(t_bool));
	if (argc == 1)
		return (1);
	while (argv[i] && check_flag(argv[i], &flags))
		i++;
	argc -= count_flag(argv, &flags);
	if (argc == 1)
		return (1);
	return (init_and_run(argc, argv, &stack, &flags));
}
