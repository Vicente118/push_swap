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
	pa(stackA, stackB);
	pa(stackA, stackB);
	print_stack(stackA);
	printf("\n");
	print_stack(stackB);
	pb(stackB, stackA);
	pb(stackB, stackA);
	print_stack(stackA);
	printf("\n");
	print_stack(stackB);
	free_stack(&(stackA->top));
	free(stackA);
	return (0);
}