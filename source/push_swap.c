#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	stackA = fill_stackA(argc, argv);
	stackB = malloc(sizeof(t_stack));
	stackB->top = NULL;
	print_stack(stackA);
	printf("\n");
	rra(stackA);
	print_stack(stackA);
	printf("\n");
	free_stack(&(stackA->top));
	free(stackA);
	return (0);
}