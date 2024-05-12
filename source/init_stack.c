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

ssize_t stack_length(t_stack *stack)
{
    if (is_empty(stack))
        return (0);
    return (stack->length);
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