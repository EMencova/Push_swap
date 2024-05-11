/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:29:56 by emencova          #+#    #+#             */
/*   Updated: 2024/04/19 16:29:58 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_n;

	if (!*src)
		return ;
	push_n = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	push_n->previous = NULL;
	if (!*dest)
	{
		*dest = push_n;
		push_n->next = NULL;
	}
	else
	{
		push_n->next = *dest;
		push_n->next->previous = push_n;
		*dest = push_n;
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
