/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:21 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/16 16:28:17 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	return (NULL);
}

t_Bool	is_empty(t_stack *stack)
{
	if (!stack)
		return (true);
	return (false);
}

size_t	stack_length(t_stack *stack)
{
	t_stack_node	*node;
	size_t			count;

	count = 0;
	node = stack->top;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}
