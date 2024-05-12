#include "push_swap.h"

void    pa(t_stack *stackA, t_stack *stackB)
{
    t_stackNode *node_to_push;
    
    node_to_push = stackA->top;
    stackA->top = stackA->top->next;
    if (stackA->top)
        stackA->top->back = NULL;
    node_to_push->back =  NULL;
    if(!stackB->top)
    {
        stackB->top = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = stackB->top;
        node_to_push->next->back = node_to_push;
        stackB->top = node_to_push;
    }
    write(1, "pa\n", 3);
}

void    pb(t_stack *stackB, t_stack *stackA)
{
    t_stackNode *node_to_push;
    
    node_to_push = stackB->top;
    stackB->top = stackB->top->next;
    if (stackB->top)
        stackB->top->back = NULL;
    node_to_push->back =  NULL;
    if(!stackA->top)
    {
        stackA->top = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = stackA->top;
        node_to_push->next->back = node_to_push;
        stackA->top = node_to_push;
    }
    write(1, "pb\n", 3);
}