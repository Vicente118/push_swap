/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:56 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/16 16:22:28 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Bool	is_sort(t_stack *stack)
{
	t_stack_node	*node;

	node = stack->top;
	while (node->next != NULL)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

float	mean_value(t_stack *stack)
{
	t_stack_node	*node;
	float			mean;
	float			count;

	node = stack->top;
	mean = 0;
	count = 0;
	while (node != NULL)
	{
		mean += node->value;
		count++;
		node = node->next;
	}
	mean = mean / count;
	return (mean);
}

void	move_mean(t_stack *stack_a, t_stack *stack_b)
{
	float	mean;

	while (stack_length(stack_a) != 5)
	{
		mean = mean_value(stack_a);
		if ((float)(stack_a->top->value) <= mean)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

void	put_index(t_stack *stack)
{
	ssize_t			index;
	t_stack_node	*node;

	index = 1;
	node = stack->top;
	while (node != NULL)
	{
		node->index = index;
		index++;
		node = node->next;
	}
}

void	put_median(t_stack *stack)
{
	t_stack_node	*node;
	ssize_t			length;

	length = stack_length(stack);
	node = stack->top;
	while (node != NULL)
	{
		if (node->index <= (length / 2) + 1)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
	}
}
