/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   adapt_strategy.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/07 22:32:07 by srosu            #+#    #+#              */
/*   Updated: 2026/05/14 11:43:27 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	adapt_strategy(t_data *s, float disorder, int *count)
{
	if (disorder == 0.0)
	{
		s->big_o.strategy = "\033[3m(none)\033[0m";
		return ;
	}
	else if (disorder < 0.2 || stack_size(&s->stack_a) <= 20)
	{
		simple_sort(&s->stack_a, &s->stack_b, count);
		s->big_o.strategy = "O\033[3m(n^2)\033[0m";
	}
	else if (disorder < 0.5 || stack_size(&s->stack_a) < 500)
	{
		medium_sort(&s->stack_a, &s->stack_b, count);
		s->big_o.strategy = "O\033[3m(n√n)\033[0m";
	}
	else
	{
		radix_sort(&s->stack_a, &s->stack_b, count);
		s->big_o.strategy = "O\033[3m(n log n)\033[0m";
	}
}
