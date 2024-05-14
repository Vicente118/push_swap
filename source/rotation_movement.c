#include "push_swap.h"

void	rotation(t_stack *stack)
{
	t_stackNode *first;
	t_stackNode	*second;
	t_stackNode *last;

	first = stack->top;
	second = first->next;
	last = stack->bottom;

	stack->top = second;
    first->next = NULL;
	first->back = stack->bottom;
	stack->bottom = first;
	stack->top->back = NULL;
	last->next = first;
}

void	ra(t_stack *stackA)
{
	rotation(stackA);
	put_index(stackA);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stackB)
{
	rotation(stackB);
	put_index(stackB);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stackA, t_stack *stackB)
{
	rotation(stackA);
	rotation(stackB);
	put_index(stackA);
	put_index(stackB);
	write(1, "rr\n", 3);
}