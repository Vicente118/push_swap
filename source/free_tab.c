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
