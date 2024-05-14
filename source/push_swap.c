#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	stackA = fill_stackA(argc, argv);
	put_index(stackA);
	put_median(stackA);

	stackB = malloc(sizeof(t_stack));
	stackB->top = NULL;

	sort_5_nodes(stackA, stackB);
	print_stack(stackA);

	free_stack(&(stackA->top));
	free(stackA);
	return (0);
}