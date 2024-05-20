#include "checker.h"

void    condition_movement(t_stack *stack_a, t_stack *stack_b, char *line)
{
        if (strcmp(line, "sa\n") == 0)
            sa(stack_a);
        if (strcmp(line, "sb\n") == 0)
            sb(stack_b);
        if (strcmp(line, "ss\n") == 0)
            ss(stack_a, stack_b);
        if (strcmp(line, "ra\n") == 0)
            ra(stack_a);
        if (strcmp(line, "rb\n") == 0)
            rb(stack_b);
        if (strcmp(line, "rr\n") == 0)
            rr(stack_a, stack_b);
        if (strcmp(line, "rra\n") == 0)
            rra(stack_a);
        if (strcmp(line, "rrb\n") == 0)
            rrb(stack_b);
        if (strcmp(line, "rrr\n") == 0)
            rrr(stack_a, stack_b);
        if (strcmp(line, "pa\n") == 0)
            pa(stack_a, stack_b);
        if (strcmp(line, "pb\n") == 0)
            pb(stack_b, stack_a);
}
void    get_command(t_stack *stack_a, t_stack *stack_b)
{
    char    *line;

    while (1)
    {
        line = get_next_line(1);
        condition_movement(stack_a, stack_b, line);
        if (strcmp(line, "\n") == 0)
            break;
    }
}

int main(int argc, char **argv)
{
    t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 2 && invalid_argv2(argv) == false)
		return (0);
	stack_a = fill_stack_a(argc, argv);
	stack_b = malloc(sizeof(t_stack));
	stack_b->top = NULL;
	stack_b->bottom = NULL;
    get_command(stack_a, stack_b);
    if (is_sort(stack_a))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    return (0);
}
