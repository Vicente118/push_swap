/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:18 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/16 16:26:14 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab_error(char **array)
{
	int	i;

	i = length_array(array);
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	print_error();
}

void	free_tab(char **array)
{
	int	i;

	i = length_array(array);
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	free_stack(t_stack_node **lst)
{
	t_stack_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->value = 0;
		free(*lst);
		*lst = tmp;
	}
}
