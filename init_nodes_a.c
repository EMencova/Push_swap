/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:47:23 by emencova          #+#    #+#             */
/*   Updated: 2024/04/20 17:47:27 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*idx_b;
	t_stack	*target;
	int		best;

	while (a)
	{
		best = -2147483648;
		idx_b = b;
		while (idx_b)
		{
			if (idx_b->nbr < a->nbr && idx_b->nbr > best)
			{
				best = idx_b->nbr;
				target = idx_b;
			}
			idx_b = idx_b->next;
		}
		if (best == -2147483648)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	current_idx(t_stack *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (!stack)
		return ;
	mid = list_size(stack) / 2;
	while (stack)
	{
		stack->indicator = i;
		if (i <= mid)
			stack->top_half = true;
		else
			stack->top_half = false;
		stack = stack->next;
		++i;
	}
}

static void	count_cost_a(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = list_size(a);
	b_len = list_size(b);
	while (a)
	{
		a->cost = a->indicator;
		if (!(a->top_half))
			a->cost = a_len - (a->indicator);
		if (a->target->top_half)
			a->cost += a->target->indicator;
		else
			a->cost += b_len - (a->target->indicator);
		a = a->next;
	}
}

void	best_move(t_stack *stack)
{
	int		cheapest;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest = 2147483647;
	while (stack)
	{
		if (stack->cost < cheapest)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_idx(a);
	current_idx(b);
	target_a(a, b);
	count_cost_a(a, b);
	best_move(a);
}
