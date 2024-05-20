/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:17 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/20 17:40:08 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	*argv_array_numbers(int argc, char **argv)
{
	ssize_t	*array_number;

	if (argc == 1)
		exit(1);
	if (argc == 2)
		array_number = parser_simple_argv(argv);
	if (argc >= 3)
		array_number = parser_multiple_argv(argc, argv);
	return (array_number);
}

t_stack	*fill_stack_a(int argc, char **argv)
{
	ssize_t		*array_number;
	t_stack		*stack_a;
	int			i;

	i = 0;
	array_number = argv_array_numbers(argc, argv);
	stack_a = init_stack();
	while (i < len_simple_array(array_number))
	{
		stack_a = add_back_stack(stack_a, array_number[i]);
		i++;
	}
	free(array_number);
	return (stack_a);
}
