/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_movement.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:30 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/20 18:59:37 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotation(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second_to_last;
	t_stack_node	*last;

	if (stack_length(stack) < 2)
		print_error();
	first = stack->top;
	last = stack->bottom;
	second_to_last = last->back;
	stack->bottom = second_to_last;
	last->back = NULL;
	last->next = stack->top;
	stack->top = last;
	second_to_last->next = NULL;
	first->back = last;
}

void	rra(t_stack *stack_a)
{
	reverse_rotation(stack_a);
	put_index(stack_a);
	put_median(stack_a);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotation(stack_b);
	put_index(stack_b);
	put_median(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	put_index(stack_a);
	put_index(stack_b);
	put_median(stack_a);
	put_median(stack_b);
}
