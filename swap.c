/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:20 by emencova          #+#    #+#             */
/*   Updated: 2024/04/19 16:30:22 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	swap(t_stack **idx)
{
	if (!*idx || !(*idx)->next)
		return ;
	*idx = (*idx)->next;
	(*idx)->previous->previous = *idx;
	(*idx)->previous->next = (*idx)->next;
	if ((*idx)->next)
		(*idx)->next->previous = (*idx)->previous;
	(*idx)->next = (*idx)->previous;
	(*idx)->previous = NULL;
}

void	swap_a(t_stack	**a, bool flag)
{
	swap(a);
	if (!flag)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **b, bool flag)
{
	swap(b);
	if (!flag)
		write(1, "sb\n", 3);
}

void	swap_both(t_stack **a, t_stack **b, bool flag)
{
	swap(a);
	swap(b);
	if (!flag)
		write(1, "ss\n", 3);
}
