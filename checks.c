/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:01:58 by emencova          #+#    #+#             */
/*   Updated: 2024/04/18 13:02:00 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	only_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < ac)
	{
		if (av[j][i] == '-' || av[j][i] == '+')
			i++;
		while (av[j][i] != '\0')
		{
			if (av[j][i] < '0' || av[j][i] > '9')
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_double(int ac, char **av)
{
	int	control;
	int	n;
	int	i;
	int	j;

	control = 0;
	i = 0;
	j = 0;
	while (++i < ac)
	{
		n = ft_atoi(av[i]);
		while (++j < ac)
		{
			if (n == ft_atoi(av[j]))
				control++;
		}
		if (control > 1)
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		j = 1;
		control = 0;
	}
	return (1);
}

bool	is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	check(int ac, char **av)
{
	if (ac < 2)
		exit(1);
	only_digits(ac, av);
	check_double(ac, av);
}
