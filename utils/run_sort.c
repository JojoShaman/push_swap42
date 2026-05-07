/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   handle_stack.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/07 22:14:31 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 22:21:57 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	run_sort(t_data *s)
{
	float	disorder;
	int		percent;
	int		*t;
	int		count;

	disorder = compute_disorder(&s->stack_a);
	percent = (int)(disorder * 10000 + 0.5);
	t = copy_into_array(&s->stack_a);
	count = 0;
	sort_array(t, stack_size(&s->stack_a));
	replace_value(t, &s->stack_a, stack_size(&s->stack_a));
	adapt_strategy(s, disorder, &count);
	if (s->flags.bench_mode)
		print_bench(*s, count, percent / 100, percent % 100);
	free(t);
	ft_lstclear(&s->stack_a);
	ft_lstclear(&s->stack_b);
	free(s);
}
