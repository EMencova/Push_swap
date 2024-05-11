/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:09 by emencova          #+#    #+#             */
/*   Updated: 2024/04/19 16:30:13 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_n;

	if (!*stack || !(*stack)->next)
		return ;
	last_n = last_nbr(*stack);
	last_n->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_n->next->previous = last_n;
	last_n->next->next = NULL;
}

void	rotate_a(t_stack **a, bool flag)
{
	rotate(a);
	if (!flag)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b, bool flag)
{
	rotate(b);
	if (!flag)
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b, bool flag)
{
	rotate(a);
	rotate(b);
	if (!flag)
		write(1, "rr\n", 3);
}
