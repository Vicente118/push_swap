/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:21 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/27 11:55:04 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

// void	free_stack(t_stack_node **lst, t_stack *stack_a)
// {
// 	t_stack_node	*tmp;

// 	if (!lst)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		(*lst)->value = 0;
// 		free(*lst);
// 		*lst = tmp;
// 	}
// 	free(stack_a);
// }