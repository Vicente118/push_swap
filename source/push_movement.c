/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:27 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/16 16:13:32 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	t_stack_node	*node_to_push;

	node_to_push = stack_b->top;
	stack_b->top = stack_b->top->next;
	if (stack_b->top)
		stack_b->top->back = NULL;
	node_to_push->back = NULL;
	if (!stack_a->top)
	{
		stack_a->top = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = stack_a->top;
		node_to_push->next->back = node_to_push;
		stack_a->top = node_to_push;
	}
	put_index(stack_a);
	put_index(stack_b);
	put_median(stack_a);
	put_median(stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*node_to_push;

	node_to_push = stack_a->top;
	stack_a->top = stack_a->top->next;
	if (stack_a->top)
		stack_a->top->back = NULL;
	node_to_push->back = NULL;
	if (!stack_b->top)
	{
		stack_b->top = node_to_push;
		node_to_push->next = NULL;
		stack_b->bottom = node_to_push;
	}
	else
	{
		node_to_push->next = stack_b->top;
		node_to_push->next->back = node_to_push;
		stack_b->top = node_to_push;
	}
	put_index(stack_a);
	put_index(stack_b);
	put_median(stack_a);
	put_median(stack_b);
	write(1, "pb\n", 3);
}
