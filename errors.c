/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:16:10 by emencova          #+#    #+#             */
/*   Updated: 2024/04/18 13:16:12 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*live;

	if (!stack)
		return ;
	live = *stack;
	while (live)
	{
		temp = live->next;
		live->nbr = 0;
		free(live);
		live = temp;
	}
	*stack = NULL;
}
