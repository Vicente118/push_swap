#include "push_swap.h"

void    assign_best_friend(t_stack *stackA, t_stack *stackB)
{
    t_stackNode *nodeA;
    t_stackNode *nodeB;
    ssize_t     sum;

    nodeB = stackB->top;
    while (nodeB != NULL)
    {
        nodeA = stackA->top;
        sum = LONG_MAX;
        while (nodeA != NULL)
        {
            if (nodeA->value - nodeB->value > 0 && nodeA->value - nodeB->value < sum)
            {
                sum = nodeA->value - nodeB->value;
                nodeB->best_friend = nodeA;
            }
            nodeA = nodeA->next;
        }
        nodeB = nodeB->next;
    }
}

void    assign_cost(t_stack *stackA, t_stack *stackB)
{
    t_stackNode *nodeB;
    t_stackNode *nodeBF;

    nodeB = stackB->top;
    while (nodeB != NULL)
    {
        nodeBF = nodeB->best_friend;
        if (nodeB->above_median)
            nodeB->cost = nodeB->index - 1;
        else
            nodeB->cost = stack_length(stackB) - nodeB->index + 1;
        if (nodeBF->above_median)
            nodeBF->cost = nodeBF->index - 1;
        else
            nodeBF->cost = stack_length(stackA) - nodeBF->index + 1;
        nodeB = nodeB->next;
    }
}

void    rise_nodeB(t_stack *stackB)
{
    t_stackNode *node;
    int         index;
    ssize_t         min;

    node = stackB->top;
    index = 0;
    min = LONG_MAX;
    while (node != NULL)
    {
        if (node->cost + node->best_friend->cost < min)
        {
            index = node->index;
            min = node->cost + node->best_friend->cost;
        }
        if(node->next == NULL)
            break ;
        node = node->next;
    }
    while (node->index != index)
        node = node->back;
    if (node->above_median == true)
		while (node->index != 1)
			rb(stackB);
	else
		while (node->index != 1)
	        rrb(stackB);
}

void    rise_nodeBF(t_stack *stackA, t_stack *stackB)
{
    t_stackNode *node;

    node = stackB->top;
    if (node->best_friend->above_median == true)
		while (node->best_friend->index != 1)
			ra(stackA);
	else
		while (node->best_friend->index != 1)
			rra(stackA);
}