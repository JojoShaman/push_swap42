/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   run_sort.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/07 22:14:31 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 02:14:47 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	run_sort(t_stack *a, t_stack *b, t_data *stacks)
{
	float	disorder;
	int		percent;
	int		*t;
	int		count;
	t_list	*track;

	disorder = compute_disorder(a);
	percent = (int)(disorder * 10000 + 0.5);
	t = copy_into_array(a);
	count = 0;
	sort_array(t, stack_size(a));
	replace_value(t, a, stack_size(a));
	//medium_sort(a, b, &count);
	//radix_sort(a, b, &count);
	if (a->bool->simple)
	{
		simple_sort(a, b, &count);
		stacks->big_o.strategy = "O\033[3m(n^2)\033[0m";
	}
	else if (a->bool->medium)
	{
		medium_sort(a, b, &count);
		stacks->big_o.strategy = "O\033[3m(n√n)\033[0m";
	}
	else if (a->bool->complex)
	{
		radix_sort(a, b, &count);
		stacks->big_o.strategy = "O\033[3m(n log n)\033[0m";
	}
	else
		adapt_strategy(stacks, disorder, &count);
	if (a->bool->bench_mode)
		print_bench(*stacks, count, percent / 100, percent % 100);
	free(t);
	ft_lstclear(a);
	ft_lstclear(b);
	free(stacks);
}
