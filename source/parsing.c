#include "push_swap.h"

ssize_t length_array(char **array)
{
    ssize_t count;

    count = 0;
    while (array[count])
        count++;
    return (count);
}

t_Bool check_doublon_error(ssize_t *tab)
{
    ssize_t *temp;
    int     i;
    int     j;

    temp = tab;
    i = 0;
    j = 0;
    while (tab[i])
    {
        while (temp[j])
        {
            if (tab[i] == temp[j] && i != j)
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

t_Bool  check_argv_error(char **array)
{
    int i;
    int j;

    i = 0;
    if (!ft_isdigit(array[0][0]) && array[0][0] != '-')
        return ((false));
    while (array[i])
    {
        j = 0;
        if (ft_big_atoi(array[i]) < -2147483648 || ft_big_atoi(array[i]) > 2147483647)
            return (false);
        while (array[i][j])
        {
            if (!ft_isdigit(array[i][j]))
            {
                if (j != 0 || (j == 0 && array[i][j] != '-') || 
                    (j == 0 && array[i][j] == '-' && !ft_isdigit(array[i][j + 1])))
                    return (false);
            }
            j++;
        }
        i++;
    }
    return (true);
}

ssize_t *parser_simple_argv(char **argv)
{
    char    **array;
    ssize_t *int_tab;
    size_t  i;

    i = 0;
    array = ft_split(argv[1], ' ');
    if (!array)
        print_error();
    if (!check_argv_error(array))
        free_tab_error(array);
    int_tab = malloc(sizeof(ssize_t) * length_array(array));
    if (!int_tab)
        free_tab_error(array);
    while (array[i])
    {
        int_tab[i] = ft_atoi(array[i]);
        i++;
    }
    if (!check_doublon_error(int_tab))
    {
        free(int_tab);
        free_tab_error(array);
    }
    free_tab(array);
    return (int_tab);
}

ssize_t *parser_multiple_argv(char  **argv)
{
    char    **array;
    char    *temp;
    ssize_t *int_tab;
    size_t  i;

    i = -1;
    temp = argv_to_array(argv);
    array = ft_split(temp, ' ');
    if (!array)
        print_error();
    free(temp);
    if (!check_argv_error(array))
        free_tab_error(array);
    int_tab = malloc(sizeof(ssize_t) * length_array(array));
    if (!int_tab)
        free_tab_error(array);
    while (array[++i])
        int_tab[i] = ft_atoi(array[i]);
    if (!check_doublon_error(int_tab))
    {
        free(int_tab);
        free_tab_error(array);
    }
    return (free_tab(array), int_tab);
}

