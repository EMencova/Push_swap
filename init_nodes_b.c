/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:38:34 by emencova          #+#    #+#             */
/*   Updated: 2024/04/21 18:38:36 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	min_to_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->top_half)
			rotate_a(a, false);
		else
			reverse_a(a, false);
	}
}

void	move_btoa(t_stack **a, t_stack **b)
{
	push_prep(a, (*b)->target, 'a');
	push_a(a, b);
}

static void	target_b(t_stack *a, t_stack *b)
{
	t_stack	*actual_a;
	t_stack	*target;
	int		best_match;

	while (b)
	{
		best_match = 2147483647;
		actual_a = a;
		while (actual_a)
		{
			if (actual_a->nbr > b->nbr && actual_a->nbr < best_match)
			{
				best_match = actual_a->nbr;
				target = actual_a;
			}
			actual_a = actual_a->next;
		}
		if (best_match == 2147483647)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_b_nodes(t_stack *a, t_stack *b)
{
	current_idx(a);
	current_idx(b);
	target_b(a, b);
}
