/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:11 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/16 16:21:35 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_best_friend(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*node_a;
	t_stack_node	*node_b;
	ssize_t			sum;

	node_b = stack_b->top;
	while (node_b != NULL)
	{
		node_a = stack_a->top;
		sum = LONG_MAX;
		while (node_a != NULL)
		{
			if (node_a->value - node_b->value > 0 && node_a->value
				- node_b->value < sum)
			{
				sum = node_a->value - node_b->value;
				node_b->best_friend = node_a;
			}
			node_a = node_a->next;
		}
		node_b = node_b->next;
	}
}

void	assign_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*node_b;
	t_stack_node	*min_bf;

	node_b = stack_b->top;
	while (node_b != NULL)
	{
		min_bf = node_b->best_friend;
		if (node_b->above_median)
			node_b->cost = node_b->index - 1;
		else
			node_b->cost = stack_length(stack_b) - node_b->index + 1;
		if (min_bf->above_median)
			min_bf->cost = min_bf->index - 1;
		else
			min_bf->cost = stack_length(stack_a) - min_bf->index + 1;
		node_b = node_b->next;
	}
}

void	rise_node_b(t_stack *stack_b)
{
	t_stack_node	*node;
	int				index;
	ssize_t			min;

	node = stack_b->top;
	index = 0;
	min = LONG_MAX;
	while (node != NULL)
	{
		if (node->cost + node->best_friend->cost < min)
		{
			index = node->index;
			min = node->cost + node->best_friend->cost;
		}
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	while (node->index != index)
		node = node->back;
	if (node->above_median == true)
		while (node->index != 1)
			rb(stack_b);
	else
		while (node->index != 1)
			rrb(stack_b);
}

void	rise_min_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*node;

	node = stack_b->top;
	if (node->best_friend->above_median == true)
		while (node->best_friend->index != 1)
			ra(stack_a);
	else
		while (node->best_friend->index != 1)
			rra(stack_a);
}
