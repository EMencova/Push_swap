/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:31:48 by emencova          #+#    #+#             */
/*   Updated: 2024/04/19 16:31:49 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_3(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		rotate_a(a, false);
	else if (((*a)->next) == biggest)
		reverse_a(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		swap_a(a, false);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;

	len = list_size(*a);
	if (len-- > 3)
		push_b(b, a);
	if (len-- > 3)
		push_b(b, a);
	while (len > 3)
	{
		init_nodes_a(*a, *b);
		move_atob(a, b);
		len--;
	}
	sort_3(a);
	while (*b)
	{
		init_b_nodes(*a, *b);
		move_btoa(a, b);
	}
	current_idx(*a);
	min_to_top(a);
}
