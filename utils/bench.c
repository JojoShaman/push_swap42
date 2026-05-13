/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/06 01:50:21 by srosu            #+#    #+#              */
/*   Updated: 2026/05/13 02:11:58 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_bench(t_data stack, int count, int whole, int frac)
{
	char	*strat;

	strat = NULL;
	if (stack.flags.adaptive)
		strat = "Adaptive";
	else if (stack.flags.complex)
		strat = "Complex";
	else if (stack.flags.medium)
		strat = "Medium";
	else if (stack.flags.simple)
		strat = "Simple";
	else
		strat = "Adaptive";
	ft_printf(2, "[bench] disorder: %d.", whole);
	if (frac < 10)
		ft_printf(2, "0");
	ft_printf(2, "%d%%\n", frac);
	ft_printf(2, "[bench] strategy: %s / %s\n", strat, stack.big_o.strategy);
	ft_printf(2, "[bench] total_ops: %d\n", count);
	ft_printf(2, "[bench] sa: %d sb: %d", stack.opp.sa, stack.opp.sb);
	ft_printf(2, " ss: %d pa: %d", stack.opp.ss, stack.opp.pa);
	ft_printf(2, " pb: %d\n", stack.opp.pb);
	ft_printf(2, "[bench] ra: %d rb: %d", stack.opp.ra, stack.opp.rb);
	ft_printf(2, " rr: %d rra: %d", stack.opp.rr, stack.opp.rra);
	ft_printf(2, " rrb: %d rrr: %d\n", stack.opp.rrb, stack.opp.rrr);
}
