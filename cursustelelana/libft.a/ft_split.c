/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:14:12 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:08 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char *str, int divider)
{
	int		words;
	char	*aux;

	words = 0;
	aux = str;
	while (*aux != '\0')
	{
		while (*aux != '\0' && *aux == divider)
			aux++;
		if (*aux != '\0')
			words++;
		while (*aux != '\0' && *aux != divider)
			aux++;
	}
	return (words);
}

static int	find_words_into_string(char *str, char **words, int divider)
{
	char	*from;
	char	*to;
	int		index;

	index = 0;
	from = str;
	while (*from != 0)
	{
		while (*from != '\0' && *from == divider)
			from++;
		if (*from != '\0')
		{
			to = from;
			while (*to != '\0' && *to != divider)
				to++;
			words[index] = ft_substr(from, 0, to - from);
			if (words [index] == 0)
				return (0);
			from = to;
			index++;
		}
	}
	return (1);
}

static void	ft_free_reserved_memory(char **words)
{
	int	index;

	index = 0;
	while (words[index] != 0)
	{
		free (words [index]);
		index++;
	}
	free(words);
}

char	**ft_split(char const *str, char divider)
{
	char	**words;
	int		num_words;

	if (str == 0)
		return (0);
	num_words = ft_count_words((char *)str, divider);
	words = (char **) ft_calloc(num_words + 1, sizeof(char *));
	if (words)
	{
		if (find_words_into_string ((char *)str, words, divider) == 0)
		{
			ft_free_reserved_memory (words);
			return (0);
		}
	}
	return (words);
}
/*
int	main(void)
{
	int		index;
	char	**split;

	split = ft_split("    Susana      Núñez       Zamora     ", ' ');
	index = 0;
	while (split[index] != 0)
	{
		printf("%s\n", split[index]);
		index++;
	}
	return (0);
}*/
