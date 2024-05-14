#include "push_swap.h"

t_stack *init_stack(void)
{
    return (NULL);
}

t_Bool is_empty(t_stack *stack)
{
    if (!stack)
        return (true);
    return (false);
}

size_t	stack_length(t_stack *stack)
{
	t_stackNode *node;
	size_t		count;

	count = 0;
	node = stack->top;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}

ssize_t stackNode_top(t_stack *stack)
{
    if (is_empty(stack))
        return (0);
    return (stack->top->value);
}

ssize_t stackNode_bottom(t_stack *stack)
{
    if (is_empty(stack))
        return (0);
    return (stack->bottom->value);
}