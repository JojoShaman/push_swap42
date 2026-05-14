/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:10:15 by srosu             #+#    #+#             */
/*   Updated: 2026/05/14 22:17:59 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

/*static int	is_valid_2(int argc, char **argv, t_bool *flags)
{
	int		i;
	int		j;
	char	c;

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
			c = argv[i][j];
			if (!((c >= '0' && c <= '9') || c == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}*/

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

	str = NULL;
	/*if (argc > 2 && (!is_valid_2(argc, argv, flags)))
		return (error(2));*/
	str = process_argv(argc, argv, flags);
	if (!str)
		return (error(2));
	if (!check_int_limits_args(str))
		return (error(2));
	if (!check_duplicate_args(str))
		return (error(2));
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
		temp_int = parse_single_arg(argv, i, &stack);
		if (temp_int != -1)
			return (temp_int);
	}
	return (init_and_run(argc, argv, &stack, &flags));
}
