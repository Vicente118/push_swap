#include "push_swap.h"

t_Bool	is_sort(t_stack *stack)
{
	t_stackNode *node;

	node = stack->top;
	while (node->next != NULL)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}
float	mean_value(t_stack *stack)
{
	t_stackNode	*node;
	float	mean;
	float	count;

	node = stack->top;
	mean = 0;
	count = 0;
	while (node != NULL)
	{
		mean += node->value;
		count++;
		node = node->next;
	}
	mean = mean / count;
	return (mean);
}

void	move_mean(t_stack *stackA, t_stack *stackB)
{
	float	mean;

	while (stack_length(stackA) != 5)
	{
		mean = mean_value(stackA);
		if ((float) (stackA->top->value) <= mean)
			pb(stackA, stackB);
		else
			ra(stackA);
	}
}
void	put_index(t_stack *stack)
{
	ssize_t		index;
	t_stackNode *node;

	index = 1;
	node = stack->top;
	while (node != NULL)
	{
		node->index = index;
		index++;
		node = node->next;
	}
}

void	put_median(t_stack *stack)
{
	t_stackNode	*node;
	ssize_t		length;

	length = stack_length(stack);
	node = stack->top;
	while (node != NULL)
	{
		if (node->index <= (length / 2) + 1)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
	}
}