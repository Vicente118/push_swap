/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:13:11 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/27 17:52:19 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_Bool	invalid_argv2(char **argv)
{
	if (!argv[1][0] || argv[1][0] == ' ')
		return (false);
	return (true);
}

void	condition1(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strncmp(line, "rra\n", 5) == 0)
		rra(stack_a);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		rrb(stack_b);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(line, "pa\n", 5) == 0)
		pa(stack_b, stack_a);
	else if (ft_strncmp(line, "pb\n", 5) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(line, "\n", 5) != 0)
	{
		free_stack(&(stack_a->top), stack_a);
		free_stack(&(stack_b->top), stack_b);
		print_error();
	}
}

void	condition2(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 5) == 0)
	{
		if (stack_length(stack_a) == 2)
			swap2nodes(stack_a);
		else
			sa(stack_a);
	}
	else if (ft_strncmp(line, "sb\n", 5) == 0)
	{
		if (stack_length(stack_b) == 2)
			swap2nodes(stack_b);
		else
			sb(stack_b);
	}
	else if (ft_strncmp(line, "ss\n", 5) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(line, "ra\n", 5) == 0)
		ra(stack_a);
	else if (ft_strncmp(line, "rb\n", 5) == 0)
		rb(stack_b);
	else if (ft_strncmp(line, "rr\n", 5) == 0)
		rr(stack_a, stack_b);
	else
		(condition1(stack_a, stack_b, line));
}

void	get_command(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(1);
		if (line == NULL)
			break ;
		condition2(stack_a, stack_b, line);
		if (ft_strncmp(line, "\n", 5) == 0)
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
	if (!stack_b)
		print_error();
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	get_command(stack_a, stack_b);
	if (is_sort(stack_a) && stack_length(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&(stack_a->top), stack_a);
	free_stack(&(stack_b->top), stack_b);
	return (0);
}
