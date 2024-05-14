#include "push_swap.h"

t_stackNode	*minimum_stack(t_stack *stack)
{
	t_stackNode	*node;
	t_stackNode *min;

	node = stack->top;
	min = node;
	while (node != NULL)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

t_stackNode	*maximum_stack(t_stack *stack)
{
	t_stackNode	*node;
	t_stackNode *max;

	node = stack->top;
	max = node;
	while (node != NULL)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}