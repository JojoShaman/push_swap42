/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_startegy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 22:32:07 by srosu             #+#    #+#             */
/*   Updated: 2026/05/10 21:11:23 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	adapt_strategy(t_data *s, float disorder, int *count)
{
	if (disorder < 0.2)
	{
		simple_sort(&s->stack_a, &s->stack_b, count);
		s->big_o.strategy = "O\033[3m(n^2)\033[0m";
	}
	else if (disorder < 0.5)
	{
		medium_sort(&s->stack_a, &s->stack_b, count);
		s->big_o.strategy = "O\033[3mn√n\033[0m";
	}
	else
	{
		radix_sort(&s->stack_a, &s->stack_b, count);
		s->big_o.strategy = "O\033[3m(n log n)\033[0m";
	}
}
