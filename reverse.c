/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:41 by emencova          #+#    #+#             */
/*   Updated: 2024/04/19 16:30:43 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_nbr(*stack);
	last->previous->next = NULL;
	last->next = *stack;
	last->previous = NULL;
	*stack = last;
	last->next->previous = last;
}

void	reverse_a(t_stack **a, bool flag)
{
	rev_rotate(a);
	if (!flag)
		write(1, "rra\n", 4);
}

void	reverse_b(t_stack **b, bool flag)
{
	rev_rotate(b);
	if (!flag)
		write(1, "rrb\n", 4);
}

void	reverse_both(t_stack **a, t_stack **b, bool flag)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!flag)
		write(1, "rrr\n", 4);
}
