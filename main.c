/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:29:10 by emencova          #+#    #+#             */
/*   Updated: 2024/04/17 13:29:13 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	check(ac, av);
	init_a(&a, av + 1);
	if (!is_sorted(a))
	{
		if (list_size(a) == 2)
			swap_a(&a, false);
		if (list_size(a) == 3)
			sort_3(&a);
		else if (list_size(a) > 3)
			sort_stack(&a, &b);
	}
	free_stack(&a);
}
