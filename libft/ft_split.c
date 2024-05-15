/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:27:55 by vdarras           #+#    #+#             */
/*   Updated: 2024/04/02 18:40:23 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	indice;

	words = 0;
	while (*s)
	{
		indice = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (indice == 0)
			{
				words++;
				indice = 1;
			}
			s++;
		}
	}
	return (words);
}

static char	*each_word(char *str, char charset)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	len = i;
	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*word_in_string(char **array, char *word, int i, char c)
{
	array[i] = each_word(word, c);
	if (!array[i])
	{
		while (i >= 0)
		{
			free(array[i]);
			i--;
		}
		free(array);
		return (NULL);
	}
	return (array[i]);
}

char	*skip_char(char *str, char c)
{
	while (*str && *str == c)
	{
		str++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	array = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!array)
		return (NULL);
	while (*str != '\0')
	{
		str = skip_char(str, c);
		if (*str)
		{
			if (word_in_string(array, str, i, c) == 0)
				return (NULL);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	array[i] = 0;
	return (array);
}
/*
int main(void)
{
	char c = ' ';
	char const *s = "   Je  suis  un    humain   ";
	char	**array = ft_split(s, c);
	printf("%s\n%s", array[0], array[1]);
	return (0);
}
*/