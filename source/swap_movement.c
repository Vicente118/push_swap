/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:35 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/16 18:47:40 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	t_stack_node	*third_node;

	first_node = stack->top;
	second_node = first_node->next;
	third_node = second_node->next;
	stack->top = second_node;
	second_node->back = NULL;
	second_node->next = first_node;
	first_node->back = second_node;
	third_node->back = first_node;
	first_node->next = third_node;
}

void	swap2nodes(t_stack *stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	first_node = stack->top;
	second_node = first_node->next;
	stack->top = second_node;
	second_node->back = NULL;
	second_node->next = first_node;
	first_node->back = second_node;
	first_node->next = NULL;
	stack->bottom = first_node;
	write(1, "sa\n", 3);
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	put_index(stack_a);
	put_median(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	put_index(stack_b);
	put_median(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	put_index(stack_a);
	put_index(stack_b);
	put_median(stack_a);
	put_median(stack_b);
	write(1, "ss\n", 3);
}
