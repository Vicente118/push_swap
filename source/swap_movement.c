#include "push_swap.h"
void    swap(t_stack *stack)
{
    t_stackNode *firstNode;
    t_stackNode *secondNode;
    t_stackNode *thirdNode;

    firstNode = stack->top;
    secondNode = firstNode->next;
    thirdNode = secondNode->next;

    stack->top = secondNode;
    secondNode->back = NULL;
    secondNode->next = firstNode;
    firstNode->back = secondNode;

    thirdNode->back = firstNode;
    firstNode->next = thirdNode;
}
void    sa(t_stack *stackA)
{
    swap(stackA);
    write(1, "sa\n", 3);
}

void    sb(t_stack *stackB)
{
    swap(stackB);
    write(1, "sb\n", 3);
}

void    ss(t_stack *stackA, t_stack *stackB)
{
    sa(stackA);
    sb(stackB);
    write(1, "ss\n", 3);
}