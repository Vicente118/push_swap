#include "push_swap.h"

ssize_t	*argv_array_numbers(int argc, char **argv)
{
	ssize_t	*array_number;

	if (argc == 1)
		exit(1);
	if (argc == 2)
		array_number = parser_simple_argv(argv);
	if (argc >= 3)
		array_number = parser_multiple_argv(argc, argv);
	return (array_number);
}

t_stack	*fill_stackA(int argc, char **argv)
{
	ssize_t	*array_number;
	t_stack	*stackA;
	int		i;

	i = 0;
	array_number = argv_array_numbers(argc, argv);
	stackA = init_stack();
	while (i <= len_simple_array(array_number))
	{
		stackA = add_back_stack(stackA, array_number[i]);
		i++;
	}
	free (array_number);
	return (stackA);
}