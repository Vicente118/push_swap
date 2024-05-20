#include "checker.c"

void	input_error()
{
	if (strcmp(line, "sa\n") != 0 && strcmp(line, "sb\n") != 0 && strcmp(line, "ss\n") != 0
	 && strcmp(line, "ra\n") != 0 && strcmp(line, "rb\n") != 0 && strcmp(line, "rr\n") != 0 
	 && strcmp(line, "rra\n") != 0 && strcmp(line, "rrb\n") != 0 &&strcmp(line, "rrr\n") != 0 
	 && strcmp(line, "pa\n") != 0 && strcmp(line, "pb\n") != 0)
	 {
	    free_stack(&(stack_a)->top, stack_a);
        free_stack(&(stack_b)->top, stack_b);
        print_error();       
	 }
	return ;
}