/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:24 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/20 17:38:50 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	length_array(char **array)
{
	ssize_t	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

t_Bool	check_doublon_error(ssize_t *tab)
{
	ssize_t	*temp;
	int		i;
	int		j;
	int		len_temp;
	int		len_tab;

	temp = tab;
	len_tab = len_simple_array(tab);
	len_temp = len_simple_array(temp);
	i = 0;
	while (i < len_tab)
	{
		j = 0;
		while (j < len_temp)
		{
			if (tab[i] == temp[j] && i != j)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_Bool	check_argv_error(char **array)
{
	int	i;
	int	j;

	i = 0;
	if (!ft_isdigit(array[0][0]) && array[0][0] != '-')
		return ((false));
	while (i < length_array(array))
	{
		j = 0;
		if (ft_big_atoi(array[i]) < -2147483648
			|| ft_big_atoi(array[i]) > INT_MAX)
			return (false);
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]))
			{
				if (j != 0 || (j == 0 && array[i][j] != '-') || (j == 0
						&& array[i][j] == '-' && !ft_isdigit(array[i][j + 1])))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

ssize_t	*parser_simple_argv(char **argv)
{
	char	**array;
	ssize_t	*int_tab;
	size_t	i;

	i = -1;
	array = ft_split(argv[1], ' ');
	if (!array)
		print_error();
	if (!check_argv_error(array))
		free_tab_error(array);
	int_tab = malloc(sizeof(ssize_t) * (length_array(array) + 1));
	if (!int_tab)
		free_tab_error(array);
	while (array[++i])
		int_tab[i] = ft_big_atoi(array[i]);
	int_tab[i] = 2147483648;
	if (!check_doublon_error(int_tab))
	{
		free(int_tab);
		free_tab_error(array);
	}
	free_tab(array);
	return (int_tab);
}

ssize_t	*parser_multiple_argv(int argc, char **argv)
{
	char	**array;
	char	*temp;
	ssize_t	*int_tab;
	size_t	i;

	i = -1;
	temp = argv_to_array(argc, argv);
	array = ft_split(temp, ' ');
	if (!array)
		print_error();
	free(temp);
	if (!check_argv_error(array))
		free_tab_error(array);
	int_tab = malloc(sizeof(ssize_t) * (length_array(array) + 1));
	if (!int_tab)
		free_tab_error(array);
	while (array[++i])
		int_tab[i] = ft_big_atoi(array[i]);
	int_tab[i] = 2147483648;
	if (!check_doublon_error(int_tab))
	{
		free(int_tab);
		free_tab_error(array);
	}
	return (free_tab(array), int_tab);
}
