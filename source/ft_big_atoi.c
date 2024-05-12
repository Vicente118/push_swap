#include "push_swap.h"

static int	skip(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

ssize_t	ft_big_atoi(char *str)
{
	ssize_t	res;
	ssize_t			signe;

	res = 0;
	signe = 1;
	str += skip((char *)str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * signe);
}

int		len_simple_array(ssize_t *array)
{
	int	count;

	count = 0;
	while (array[count] != INT_MAX)
		count++;
	return (count);
}