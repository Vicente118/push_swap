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
	while (temp->next!= NULL)
	{
		ft_printf("[%d] ", temp->value);
		temp = temp->next;
	}
}