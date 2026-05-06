/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:15 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 02:29:16 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_data	*stack;
	int		*tab;
	char	*str;
	char	*tmp;
	int		count;
	float	disorder;
	int		percent;
	int		whole;
	int		frac;

	i = 1;
	j = 0;
	count = 0;
	str = NULL;
	tmp = NULL;
	if (argc < 2)
		return (error(2));
	if (argc == 2)
	{
		if (!check_argv(argv[i]))
			return (error(2));
		if (count_nb(argv[i]) > 1)
			stack = create_stack_a(argv[i]);
		else
			return (error(2));
	}
	else if (argc > 2)
	{
		while (i < argc)
		{
			if (!check_argv(argv[i]))
			{
				if (str)
					free(str);
				return (error(2));
			}
			tmp = str;
			str = ft_strjoin(tmp, argv[i]);
			if (tmp)
				free(tmp);
			if (i != argc - 1)
			{
				tmp = str;
				str = ft_strjoin(tmp, " ");
				free(tmp);
			}
			i++;
		}
		stack = create_stack_a(str);
		if (!stack)
		{
			free(stack);
			return (1);
		}
	}
	if (str)
		free(str);
	if (stack)
	{
		disorder = compute_disorder(&stack->stack_a);
		percent = (int)(disorder * 10000 + 0.5);
		whole = percent / 100;
		frac = percent % 100;
		tab = copy_into_array(&stack->stack_a);
		sort_array(tab, (stack->stack_a.tail->current_position + 1));
		replace_value(tab, &stack->stack_a, (stack->stack_a.tail->current_position + 1));
		//simple_sort(&stack->stack_a, &stack->stack_b, &count);
		radix_sort(&stack->stack_a, &stack->stack_b, &count);
		ft_printf("\n");
		print_bench(*stack, count, whole, frac);
		// print_stack(&stack->stack_a);
		// if (tab)
		// {
		// 	while (j < stack->stack_a.tail->current_position + 1)
		// 	{
		// 		ft_printf("%d\n", tab[j]);
		// 		j++;
		// 	}
		// 	free(tab);
		// }
		free(tab);
		ft_lstclear(&stack->stack_a);
		ft_lstclear(&stack->stack_b);
		free(stack);
	}
	return (0);
}
