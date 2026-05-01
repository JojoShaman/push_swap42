/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/28 16:51:32 by srosu            #+#    #+#              */
/*   Updated: 2026/05/01 15:27:21 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	above_median(t_stack *a, t_stack *b)
{
	int		lst_size_a;
	int		lst_size_b;
	t_list	*track_a;
	t_list	*track_b;

	if (!a || !a->head)
		return ;
	lst_size_a = a->tail->current_position;
	track_a = a->head;
	track_b = NULL;
	lst_size_b = 0;
	while (track_a)
	{
		if (track_a->current_position <= (lst_size_a - (lst_size_a / 2)))
			track_a->above_median = 1;
		else
			track_a->above_median = 0;
		track_a = track_a->next;
	}
	if (b && b->head)
	{
		lst_size_b = b->tail->current_position;
		track_b = b->head;
		while (track_b)
		{
			if (track_b->current_position <= (lst_size_b - (lst_size_b / 2)))
				track_b->above_median = 1;
			else
				track_b->above_median = 0;
			track_b = track_b->next;
		}
	}
}

void	b_target(t_stack *a, t_stack *b)
{
	t_list	*a_track;
	t_list	*b_track;
	t_list	*best;
	int		diff;
	int		best_diff;

	if ((!a || !a->head) || (!b || !b->head))
		return ;
	a_track = a->head;
	while (a_track)
	{
		best = NULL;
		best_diff = INT_MAX;
		b_track = b->head;
		while (b_track)
		{
			if (b_track->value < a_track->value)
			{
				diff = a_track->value - b_track->value;
				if (diff < best_diff)
				{
					best_diff = diff;
					best = b_track;
				}
			}
			b_track = b_track->next;
		}
		if (!best)
			best = find_biggest(b);
		a_track->target_node = best;
		a_track = a_track->next;
	}
}

void	a_target(t_stack *b, t_stack *a)
{
	t_list	*b_track;
	t_list	*a_track;
	t_list	*best;
	int		diff;
	int		best_diff;

	if ((!a || !a->head) || (!b || !b->head))
		return ;
	b_track = b->head;
	while (b_track)
	{
		best = NULL;
		best_diff = INT_MAX;
		a_track = a->head;
		while (a_track)
		{
			if (b_track->value < a_track->value)
			{
				diff = a_track->value - b_track->value;
				if (diff < best_diff)
				{
					best_diff = diff;
					best = a_track;
				}
			}
			a_track = a_track->next;
		}
		if (!best)
			best = find_smallest(a);
		b_track->target_node = best;
		b_track = b_track->next;
	}
}

void	get_cost(t_stack *stack, t_stack *stack2)
{
	t_list	*track;
	int		lst_size;
	int		lst_size2;
	int		cost;

	if ((!stack || !stack->head) || (!stack2 || !stack2->head))
		return ;
	track = stack->head;
	lst_size = stack->tail->current_position;
	lst_size2 = stack2->tail->current_position;
	cost = 0;
	while (track)
	{
		if (track->above_median)
		{
			if (track->target_node->above_median)
				cost = track->current_position + track->target_node->current_position;
			else
				cost = track->current_position + (lst_size2 - track->target_node->current_position) + 1;
		}
		else
		{
			if (track->target_node->above_median)
				cost = ((lst_size - track->current_position) + 1) + track->target_node->current_position;
			else
				cost = ((lst_size - track->current_position) + 1) + ((lst_size2 - track->target_node->current_position) + 1);
		}
		track->cost = cost;
		track = track->next;
	}
}

void	find_cheap(t_stack *stack1, t_stack *stack2, int check1, int check2)
{
	t_list	*cheapest;
	t_list	*track;

	cheapest = stack1->head;
	track = stack1->head->next;
	if (!track)
	{
		while (stack1->head->target_node->current_position > 0)
		{
			if (stack1->head->target_node->above_median)
				rotate(stack2, check2);
			else
				reverse_rotate(stack2, check2);
			above_median(stack2, stack2);
		}
		push(stack2, stack1, check2);
		return ;
	}
	while (track)
	{
		if (cheapest->cost < track->cost)
			track = track->next;
		else if (cheapest->cost > track->cost)
		{
			cheapest = track;
			track = track->next;
		}
		else if (cheapest->cost == track->cost)
			track = track->next;
	}
	//printf("\n[cheapest: %d], [target: %d]\n", cheapest->current_position, cheapest->target_node->current_position);
	if (cheapest->current_position == 0 && cheapest->target_node->current_position == 0)
	{
		push(stack2, stack1, check2);
		return ;
	}
	else
	{
		if (cheapest->above_median && cheapest->target_node->above_median)
		{
			if (cheapest->current_position && cheapest->target_node->current_position)
				rotate_both(stack1, stack2);
			else if (!cheapest->current_position && cheapest->target_node->current_position)
				rotate(stack2, check2);
			else if (cheapest->current_position && !cheapest->target_node->current_position)
				rotate(stack1, check1);
		}
		else if (!cheapest->above_median && !cheapest->target_node->above_median)
			reverse_rotate_both(stack1, stack2);
		else if (!cheapest->above_median && cheapest->target_node->above_median)
		{
			if (cheapest->target_node->current_position == 0)
				reverse_rotate(stack1, check1);
			else
				rotate(stack2, check2);
		}
		else if (cheapest->above_median && !cheapest->target_node->above_median)
		{
			if (cheapest->current_position != 0)
				rotate(stack1, check1);
			else
				reverse_rotate(stack2, check2);
		}
	}
}

void	update_info(t_stack *a, t_stack *b)
{
	above_median(a, b);
	a_target(b, a);
	b_target(a, b);
	get_cost(a, b);
	get_cost(b, a);
}

void	sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (a->tail->current_position < 3)
	{
		tiny_sort_a(a, 1);
		return ;
	}
	// push(b, a, 0);
	// update_info(a, b);
	// printf("test");
	while (1)
	{
		if (j <= 3)
			push(b, a, 0);
		if (j == 3)
		{
			tiny_sort_b(b, 0);
			break ;
		}
		update_info(a, b);
		j++;
	}
	while (a->tail->current_position > 2)
	{
		update_info(a, b);
		find_cheap(a, b, 1, 0);
	}
	if (a->tail->current_position == 2)
		tiny_sort_a(a, 1);
	else if (a->tail->current_position < 2)
	{
		if (a->head->value > a->head->next->value)
			swap(a, 1);
	}
	while (b->head)
	{
		find_cheap(b, a, 0, 1);
		update_info(a, b);
	}
	while (1)
	{
		if (!find_smallest(a)->above_median)
			reverse_rotate(a, 1);
		else
			rotate(a, 1);
		above_median(a, b);
		if (find_smallest(a)->current_position == 0)
			break ;
	}
}
