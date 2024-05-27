/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:09 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/27 11:39:28 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	ra_sa(t_stack *stackA)
{
	ra(stackA);
	sa(stackA);
}

void	sort_3_nodes(t_stack *stack)
{
	t_stack_node	*node1;
	t_stack_node	*node2;
	t_stack_node	*node3;

	node1 = stack->top;
	node2 = node1->next;
	node3 = node2->next;
	if (node1->value > node2->value && node2->value > node3->value
		&& node1->value > node3->value)
		ra_sa(stack);
	else if (node1->value < node2->value && node2->value > node3->value
		&& node1->value < node3->value)
	{
		rra(stack);
		sa(stack);
	}
	else if (node1->value > node2->value && node2->value < node3->value
		&& node1->value < node3->value)
		sa(stack);
	else if (node1->value > node2->value && node2->value < node3->value
		&& node1->value > node3->value)
		ra(stack);
	else if (node1->value < node2->value && node2->value > node3->value
		&& node1->value > node3->value)
		rra(stack);
}

void	sort_4_nodes(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*min_node;

	min_node = minimum_stack(stack_a);
	put_index(stack_a);
	put_median(stack_a);
	if (min_node->above_median == true)
		while (min_node->index != 1)
			ra(stack_a);
	else
		while (min_node->index != 1)
			rra(stack_a);
	pb(stack_a, stack_b);
	if (is_sort(stack_a) == false)
		sort_3_nodes(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5_nodes(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*min_node;
	t_stack_node	*min_node2;

	min_node = minimum_stack(stack_a);
	if (min_node->above_median == true)
		while (min_node->index != 1)
			ra(stack_a);
	else
		while (min_node->index != 1)
			rra(stack_a);
	pb(stack_a, stack_b);
	min_node2 = minimum_stack(stack_a);
	if (min_node2->above_median == true)
		while (min_node2->index != 1)
			ra(stack_a);
	else
		while (min_node2->index != 1)
			rra(stack_a);
	if (is_sort(stack_a) == false)
	{
		pb(stack_a, stack_b);
		sort_3_nodes(stack_a);
		sort_2_nodes_b(stack_a, stack_b);
	}
	put_median(stack_a);
}
