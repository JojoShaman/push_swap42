/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:15 by srosu            #+#    #+#              */
/*   Updated: 2026/04/28 19:08:05 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(int c)
{
	return ((c >= '0' && c <= '9') || (c == ' '));
}

int	check_argv(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (!is_valid(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}

float	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*track;
	int		i;

	mistakes = 0;
	total_pairs = 0;
	track = stack->head;
	while (track)
	{
		if (track->next && track->value > track->next->value)
			mistakes += 1;
		track = track->next;
		total_pairs += 1;
	}
	printf("total_p: %d, mistakes: %d\n", total_pairs, mistakes);
	return ((float) mistakes / total_pairs);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_data	*stack;
	t_list	*biggest;
	t_list	*smallest;
	char	*str;
	char	*tmp;

	i = 1;
	j = 0;
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
	}
	if (str)
		free(str);
	if (stack)
	{
		printf("%f\n-----------------------\n", compute_disorder(&stack->stack_a));
		// push(&stack->stack_b, &stack->stack_a);
		// push(&stack->stack_b, &stack->stack_a);
		// push(&stack->stack_b, &stack->stack_a);
		// tiny_sort_b(&stack->stack_b);
		sort(&stack->stack_a, &stack->stack_b);
		b_target(&stack->stack_a, &stack->stack_b);
		print_stack(&stack->stack_a, 1);
		printf("\n-----------------------\n");
		print_stack(&stack->stack_b, 0);
		// printf("\n-----------------------\n");
		// print_stack(&stack->stack_b);
		ft_lstclear(&stack->stack_a);
	}
	return (0);
}
