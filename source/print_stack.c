/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:26 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/24 13:34:48 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack_node	*temp;

	temp = stack->top;
	if (is_empty(stack))
	{
		write(1, "Liste vide", 10);
		return ;
	}
	while (temp != NULL)
	{
		temp = temp->next;
	}
}
