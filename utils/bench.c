/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/06 01:50:21 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 02:27:39 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_bench(t_data stack, int count, int whole, int frac)
{
	ft_printf("[bench] disorder: %d.", whole);
	if (frac < 10)
		ft_printf("0");
	ft_printf("%d%%\n", frac);
	ft_printf("[bench] total_ops: %d\n", count);
	ft_printf("[bench] sa: %d sb: %d", stack.opp.sa, stack.opp.sb);
	ft_printf(" ss: %d pa: %d", stack.opp.ss, stack.opp.pa);
	ft_printf(" pb: %d\n", stack.opp.pb);
	ft_printf("[bench] ra: %d rb: %d", stack.opp.ra, stack.opp.rb);
	ft_printf(" rr: %d rra: %d", stack.opp.rr, stack.opp.rra);
	ft_printf(" rrb: %d rrr: %d\n", stack.opp.rrb, stack.opp.rrr);
}
