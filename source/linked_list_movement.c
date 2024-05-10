#include "push_swap.h"

t_stack *add_back_stack(t_stack *stack, ssize_t number)
{
    t_stackNode *node;

    node = malloc(sizeof(t_stackNode));
    if(!node)
        print_error();
    node->value = number;
    node->next = NULL;
    node->back = NULL;
    if (is_empty(stack))
    {
        stack = malloc(sizeof(t_stack));
        if(!stack)
        {
            free(node);
            print_error();
        }
        stack->length = 0;
        stack->top = node;
        stack->bottom = node;
    }
    else
    {
        stack->bottom->next = node;
        node->back = stack->bottom;
        stack->bottom = node;
    }
    stack->length++;
    return (stack);
}
