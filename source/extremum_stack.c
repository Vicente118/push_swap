/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremum_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:15 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/16 16:23:12 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*minimum_stack(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_node	*min;

	node = stack->top;
	min = node;
	while (node != NULL)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

t_stack_node	*maximum_stack(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_node	*max;

	node = stack->top;
	max = node;
	while (node != NULL)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}
