/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:08:12 by emencova          #+#    #+#             */
/*   Updated: 2024/04/21 16:08:14 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push_prep(t_stack **stack, t_stack *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->top_half)
				rotate_a(stack, false);
			else
				reverse_a(stack, false);
		}
		else if (name == 'b')
		{
			if (top->top_half)
				rotate_b(stack, false);
			else
				reverse_b(stack, false);
		}
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack == find_cheapest(stack))
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest_n)
{
	while (*b != cheapest_n->target && *a != cheapest_n)
		rotate_both(a, b, false);
	current_idx(*a);
	current_idx(*b);
}

void	rev_rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest_n)
{
	while (*b != cheapest_n->target && *a != cheapest_n)
		reverse_both(a, b, false);
	current_idx(*a);
	current_idx(*b);
}

void	move_atob(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_n;

	cheapest_n = get_cheapest(*a);
	if (cheapest_n->top_half && cheapest_n->target->top_half)
		rotate_ab(a, b, cheapest_n);
	else if (!(cheapest_n->top_half) && !(cheapest_n->target->top_half))
		rev_rotate_ab(a, b, cheapest_n);
	push_prep(a, cheapest_n, 'a');
	push_prep(b, cheapest_n->target, 'b');
	push_b(b, a);
}
