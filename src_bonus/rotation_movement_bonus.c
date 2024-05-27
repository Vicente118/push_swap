/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_movement_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:32 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/27 17:55:43 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotation(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*last;

	if (stack_length(stack) < 2)
		return ;
	first = stack->top;
	second = first->next;
	last = stack->bottom;
	stack->top = second;
	first->next = NULL;
	first->back = stack->bottom;
	stack->bottom = first;
	stack->top->back = NULL;
	last->next = first;
}

void	ra(t_stack *stack_a)
{
	rotation(stack_a);
	put_index(stack_a);
	put_median(stack_a);
}

void	rb(t_stack *stack_b)
{
	rotation(stack_b);
	put_index(stack_b);
	put_median(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotation(stack_a);
	rotation(stack_b);
	put_index(stack_a);
	put_index(stack_b);
	put_median(stack_a);
	put_median(stack_b);
}
