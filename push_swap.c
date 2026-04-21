/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:15 by srosu            #+#    #+#              */
/*   Updated: 2026/04/21 14:13:15 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	input[20];
	t_data	*stack;

	i = 0;
	if (argc < 2)
		return (0);
	stack = create_stack_a(argv[1]);
	print_stack(&stack->stack_a);
	ft_printf("\n--------------------------\n\n");
	swap(&stack->stack_a);
	print_stack(&stack->stack_a);
	return (0);
}
