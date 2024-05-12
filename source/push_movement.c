#include "push_swap.h"

void    pa(t_stack *stackA, t_stack *stackB)
{
    t_stackNode *nodeA = stackA->top;

    stackA->top = nodeA->next;
    if (stackA->top == NULL)
        stackA->bottom = NULL;
    else
        stackA->top->back = NULL;
    stackA->length--;

    nodeA->next = stackB->top;
    nodeA->back = NULL;
    if (stackB->top == NULL)
        stackB->bottom = nodeA;
        stackB->bottom->next = NULL;
    stackB->top = nodeA;
    stackB->length++;

}

