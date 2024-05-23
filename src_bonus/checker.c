/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:13:11 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/23 12:22:22 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_Bool	invalid_argv2(char **argv)
{
	if (!argv[1][0] || argv[1][0] == ' ')
		return (false);
	return (true);
}

void	condition1(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (strcmp(line, "sa\n") == 0)
	{
		if (stack_length(stack_a) == 2)
			swap2nodes(stack_a);
		else
			sa(stack_a);
	}
	else if (strcmp(line, "sb\n") == 0)
	{
		if (stack_length(stack_b) == 2)
			swap2nodes(stack_b);
		else
			sb(stack_b);
	}
}

void	condition2(t_stack *stack_a, t_stack *stack_b, char *line)
{
	condition1(stack_a, stack_b, line);
	if (strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (strcmp(line, "pa\n") == 0)
		pa(stack_b, stack_a);
	else if (strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (strcmp(line, "\n") != 0)
	{
		free_stack(&(stack_a->top), stack_a);
		free_stack(&(stack_b->top), stack_b);
		print_error();
	}
}

void	get_command(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(1);
		condition2(stack_a, stack_b, line);
		if (strcmp(line, "\n") == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 2 && invalid_argv2(argv) == false)
		return (0);
	stack_a = fill_stack_a(argc, argv);
	stack_b = malloc(sizeof(t_stack));
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	get_command(stack_a, stack_b);
	if (is_sort(stack_a))
		printf("OK\n");
	else
		printf("KO\n");
	free_stack(&(stack_a->top), stack_a);
	free_stack(&(stack_b->top), stack_b);
	return (0);
}
