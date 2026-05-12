/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:10:15 by srosu             #+#    #+#             */
/*   Updated: 2026/05/12 21:42:00 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	init_and_run(int argc, char **argv, t_data **stack)
{
	char	*str;
	t_bool	flags;

	str = NULL;
	ft_memset(&flags, 0, sizeof(t_bool));
	if (check_duplicate_args(argc, argv) == 0)
		return (error(2));
	str = process_argv(argc, argv, &flags);
	if (!str)
		return (error(2));
	*stack = create_stack_a(str);
	free(str);
	if (!*stack)
		return (1);
	(*stack)->flags = flags;
	run_sort(&(*stack)->stack_a, &(*stack)->stack_b, *stack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*stack;
	int		temp_int;

	if (argc < 2)
		return (error(2));
	if (argc == 2)
	{
		temp_int = parse_single_arg(argv, 1, &stack);
		if (temp_int != -1)
			return (temp_int);
	}
	return (init_and_run(argc, argv, &stack));
}
