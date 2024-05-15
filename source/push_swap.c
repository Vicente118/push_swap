#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	stackA = fill_stackA(argc, argv);
	stackB = malloc(sizeof(t_stack));
	stackB->top = NULL;
	stackB->bottom = NULL;
	put_index(stackA);
	put_median(stackA);

	move_mean(stackA, stackB);
	sort_5_nodes(stackA, stackB);

	while(stack_length(stackB) != 0)
	{
		assign_best_friend(stackA, stackB);
		assign_cost(stackA, stackB);
		rise_nodeB(stackB);
		rise_nodeBF(stackA, stackB);
		pa(stackB, stackA);
	}
	while (is_sort(stackA) == false)
		rra(stackA);
	free_stack(&(stackA->top));
	free(stackA);
	free(stackB);
	return (0);
}