/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:15 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 17:55:23 by srosu           ###   ########.fr        */
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

void	adapt_strategy(t_data *s, float disorder, int *count)
{
	if (disorder < 0.2)
	{
		simple_sort(&s->stack_a, &s->stack_b, count);
		s->big_o.strategy = "O\033[3m(n^2)\033[0m";
	}
	else
	{
		radix_sort(&s->stack_a, &s->stack_b, count);
		s->big_o.strategy = "O\033[3m(n log n)\033[0m";
	}
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
	adapt_strategy(s, disorder, &count);
	if (s->flags.bench_mode)
		print_bench(*s, count, percent / 100, percent % 100);
	free(t);
	ft_lstclear(&s->stack_a);
	ft_lstclear(&s->stack_b);
	free(s);
}

int	check_flag(char *str, t_bool *flags)
{
	if (ft_strcmp(str, "--bench") == 0)
	{
		flags->bench_mode = 1;
		return (1);
	}
	if (ft_strcmp(str, "--adaptive") == 0)
	{
		flags->adaptive = 1;
		return (1);
	}
	return (0);
}

int	handle_main(int argc, char **argv, t_data **stack)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;
	t_bool	flags;

	str = NULL;
	tmp = NULL;
	j = 0;
	i = 1;
	ft_memset(&flags, 0, sizeof(t_bool));
	if (argc > 2)
	{
		while (i < argc)
		{
			if (!check_flag(argv[i], &flags))
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
		(*stack)->flags = flags;
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
	}
	return (handle_main(argc, argv, &stack));
}
