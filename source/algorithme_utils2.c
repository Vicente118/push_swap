#include "push_swap.h"

void	sort_2_nodesB(t_stack *stackA, t_stack *stackB)
{
	t_stackNode	*node;

	node = stackB->top;
	pa(stackB, stackA);
	pa(stackB, stackA);
}
void	sort_3_nodes(t_stack *stack)
{
	t_stackNode	*node1;
	t_stackNode *node2;
	t_stackNode	*node3;

	node1 = stack->top;
	node2 = node1->next;
	node3 = node2->next;
	if (node1->value > node2->value && node2->value > node3->value && node1->value > node3->value)
	{
		ra(stack);
		sa(stack);
	}
	else if (node1->value < node2->value && node2->value > node3->value && node1->value < node3->value)
	{
		rra(stack);
		sa(stack);
	}
	else if (node1->value > node2->value && node2->value < node3->value && node1->value < node3->value)
		sa(stack);
	else if (node1->value > node2->value && node2->value < node3->value && node1->value > node3->value)
		ra(stack);
	else if (node1->value < node2->value && node2->value > node3->value && node1->value > node3->value)
		rra(stack);
}
void	sort_5_nodes(t_stack *stackA, t_stack *stackB)
{
	t_stackNode *minNode;
	t_stackNode *minNode2;

	minNode = minimum_stack(stackA);
	printf("%ld\n\n", minNode->value);
	if (minNode->above_median == true)
		while (minNode->index != 1)
			ra(stackA);
	else
		while (minNode->index != 1)
			rra(stackA);
	pb(stackA, stackB);
	minNode2 = minimum_stack(stackA);
	printf("%ld\n\n", minNode2->value);
	if (minNode2->above_median == true)
		while (minNode2->index != 1)
			ra(stackA);
	else
		while (minNode2->index != 1)
			rra(stackA);
	pb(stackA, stackB);
	sort_3_nodes(stackA);
	sort_2_nodesB(stackA, stackB);
	put_median(stackA);
}
