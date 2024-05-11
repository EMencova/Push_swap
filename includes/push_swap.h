/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:51 by emencova          #+#    #+#             */
/*   Updated: 2024/04/17 13:28:54 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				indicator;
	int				cost;
	bool			cheapest;
	bool			top_half;

	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*previous;
}		t_stack;
void	free_stack(t_stack **stack);
void	check(int ac, char **av);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	swap_a(t_stack **a, bool print);
void	swap_b(t_stack **b, bool print);
void	swap_both(t_stack **a, t_stack **b, bool print);
void	reverse_a(t_stack **a, bool print);
void	reverse_b(t_stack **b, bool print);
void	reverse_both(t_stack **a, t_stack **b, bool print);
void	rotate_a(t_stack **a, bool print);
void	rotate_b(t_stack **b, bool print);
void	rotate_both(t_stack **a, t_stack **b, bool print);
void	sort_3(t_stack **a);
void	move_atob(t_stack **a, t_stack **b);
void	init_b_nodes(t_stack *a, t_stack *b);
void	init_nodes_a(t_stack *a, t_stack *b);
void	move_btoa(t_stack **a, t_stack **b);
void	min_to_top(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);
void	init_a(t_stack **a, char **av);
void	push_prep(t_stack **stack, t_stack *top, char name);
void	current_idx(t_stack *stack);
void	move_atob(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest_n);
void	rev_rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest_n);

int		list_size(t_stack *stack);
int		main(int ac, char **av);
bool	is_sorted(t_stack *stack);

t_stack	*get_cheapest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*last_nbr(t_stack *stack);

long	ft_atoi(const char *s);

#endif