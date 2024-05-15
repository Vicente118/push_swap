#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stackNode *temp;

	temp = stack->top;
	if(is_empty(stack))
	{
		ft_printf("Liste vide");
		return ;
	}
	while (temp != NULL)
	{
		printf("[%ld]  index : %ld  --- above mediane : %u\n", temp->value, temp->index, temp->above_median);
		temp = temp->next;
	}
}
