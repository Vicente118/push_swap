#include "push_swap.h"

void    free_tab_error(char **array)
{
    int i;

    i = length_array(array);
    while (i >= 0)
    {
        free(array[i]);
        i--;
    }
    free(array);
    print_error();
}
void    free_tab(char **array)
{
    int i;

    i = length_array(array);
    while (i >= 0)
    {
        free(array[i]);
        i--;
    }
    free(array);
}
void	free_stack(t_stackNode **lst)
{
	t_stackNode	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->value = 0;
		free(*lst);
		*lst = tmp;
	}
}