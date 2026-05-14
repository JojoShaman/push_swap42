/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   run_sort.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/07 22:14:31 by srosu            #+#    #+#              */
/*   Updated: 2026/05/14 11:17:35 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	if_flag(t_stack *a, t_stack *b, t_data *stacks, int *count)
{
	if (a->flag_check->simple)
	{
		simple_sort(a, b, count);
		stacks->big_o.strategy = "O\033[3m(n^2)\033[0m";
		return (1);
	}
	else if (a->flag_check->medium)
	{
		medium_sort(a, b, count);
		stacks->big_o.strategy = "O\033[3m(n√n)\033[0m";
		return (1);
	}
	else if (a->flag_check->complex)
	{
		radix_sort(a, b, count);
		stacks->big_o.strategy = "O\033[3m(n log n)\033[0m";
		return (1);
	}
	return (0);
}

void	run_sort(t_stack *a, t_stack *b, t_data *stacks)
{
	float	disorder;
	int		percent;
	int		*t;
	int		count;

	disorder = compute_disorder(a);
	percent = (int)(disorder * 10000 + 0.5);
	t = copy_into_array(a);
	count = 0;
	sort_array(t, stack_size(a));
	replace_value(t, a, stack_size(a));
	if (!if_flag(a, b, stacks, &count))
		adapt_strategy(stacks, disorder, &count);
	if (a->flag_check->bench_mode)
		print_bench(*stacks, count, percent / 100, percent % 100);
	free(t);
	ft_lstclear(a);
	ft_lstclear(b);
	free(stacks);
}
