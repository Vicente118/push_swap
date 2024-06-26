/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:12 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/24 16:57:30 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_count(int argc, char **argv)
{
	int	count;
	int	i;
	int	j;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			count++;
			j++;
		}
		count++;
		i++;
	}
	return (count);
}

char	*argv_to_array(int argc, char **argv)
{
	char	*string;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	string = malloc(sizeof(char) * (argv_count(argc, argv) + argc));
	if (!string)
		print_error();
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			string[k] = argv[i][j];
			k++;
			j++;
		}
		string[k] = ' ';
		k++;
		i++;
	}
	string[k] = '\0';
	return (string);
}
