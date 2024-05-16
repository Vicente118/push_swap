/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:23 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/16 16:08:15 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_back_stack(t_stack *stack, ssize_t number)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		print_error();
	node->value = number;
	node->next = NULL;
	node->back = NULL;
	node->above_median = 0;
	if (is_empty(stack))
	{
		stack = malloc(sizeof(t_stack));
		if (!stack)
		{
			free(node);
			print_error();
		}
		stack->length = 0;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		node->back = stack->bottom;
		stack->bottom = node;
	}
	stack->length++;
	return (stack);
}
