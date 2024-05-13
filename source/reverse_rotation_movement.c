#include "push_swap.h"

void	reverse_rotation(t_stack *stack)
{
	t_stackNode *first;
	t_stackNode	*second_to_last;
	t_stackNode *last;

	first = stack->top;
	last = stack->bottom;
	second_to_last = last->back;

	stack->bottom = second_to_last;
	last->back = NULL;
	last->next = stack->top;
	stack->top = last;
	second_to_last->next = NULL;
	first->back = last;
}

void	rra(t_stack *stackA)
{
	reverse_rotation(stackA);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stackB)
{
	reverse_rotation(stackB);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stackA, t_stack *stackB)
{
	reverse_rotation(stackA);
	reverse_rotation(stackB);
	write(1, "rrr\n", 4);
}