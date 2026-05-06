/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:15 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 12:27:23 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	handle_argv2(char **argv, int i, t_data **stack)
{
	if (!check_argv(argv[i]))
		return (error(2));
	if (count_nb(argv[i]) > 1)
		*stack = create_stack_a(argv[i]);
	else
		return (error(2));
	return (-1);
}

void	handle_stack(t_data *s)
{
	float	disorder;
	int		percent;
	int		*t;
	int		count;

	disorder = compute_disorder(&s->stack_a);
	percent = (int)(disorder * 10000 + 0.5);
	t = copy_into_array(&s->stack_a);
	count = 0;
	sort_array(t, (s->stack_a.tail->current_position + 1));
	replace_value(t, &s->stack_a, (s->stack_a.tail->current_position + 1));
	radix_sort(&s->stack_a, &s->stack_b, &count);
	ft_printf("\n");
	print_bench(*s, count, percent / 100, percent % 100);
	free(t);
	ft_lstclear(&s->stack_a);
	ft_lstclear(&s->stack_b);
	free(s);
}

int	handle_main(int argc, char **argv, t_data **stack)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	str = NULL;
	tmp = NULL;
	j = 0;
	i = 1;
	if (argc > 2)
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
		*stack = create_stack_a(str);
		if (!*stack)
		{
			if (str)
				free(str);
			return (1);
		}
	}
	if (str)
		free(str);
	if (*stack)
		handle_stack(*stack);
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
		temp_int = handle_argv2(argv, 1, &stack);
		if (temp_int != -1)
			return (temp_int);
		return (0);
	}
	return (handle_main(argc, argv, &stack));
}
