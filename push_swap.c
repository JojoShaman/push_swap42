/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:15 by srosu            #+#    #+#              */
/*   Updated: 2026/05/05 00:48:21 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_data	*stack;
	t_list	*biggest;
	t_list	*smallest;
	char	*str;
	char	*tmp;

	i = 1;
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
		//printf("%f\n-----------------------\n", compute_disorder(&stack->stack_a));
		sort(&stack->stack_a, &stack->stack_b);
		ft_lstclear(&stack->stack_a);
		ft_lstclear(&stack->stack_b);
		free(stack);
	}
	return (0);
}
