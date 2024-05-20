/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:29 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/20 14:14:24 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Bool	invalid_argv2(char **argv)
{
	if (!argv[1][0] || argv[1][0] == ' ')
		return (false);
	return (true);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	put_index(stack_a);
	put_median(stack_a);
	move_mean(stack_a, stack_b);
	sort_5_nodes(stack_a, stack_b);
	while (stack_length(stack_b) != 0)
	{
		assign_best_friend(stack_a, stack_b);
		assign_cost(stack_a, stack_b);
		rise_node_b(stack_b);
		rise_min_node(stack_a, stack_b);
		pa(stack_b, stack_a);
	}
	while (is_sort(stack_a) == false)
		rra(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 2 && invalid_argv2(argv) == false)
		return (0);
	stack_a = fill_stack_a(argc, argv);
	stack_b = malloc(sizeof(t_stack));
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	if (stack_length(stack_a) == 2)
		if (!is_sort(stack_a))
			swap2nodes(stack_a);
	if (stack_length(stack_a) == 3)
		sort_3_nodes(stack_a);
	if (stack_length(stack_a) == 4)
	{
		put_index(stack_a);
		put_median(stack_a);
		sort_4_nodes(stack_a, stack_b);
	}
	if (stack_length(stack_a) >= 5)
		push_swap(stack_a, stack_b);
	free_stack(&(stack_a->top), stack_a);
	free(stack_b);
	return (0);
}
