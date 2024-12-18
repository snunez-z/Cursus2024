#include <stdio.h>
#include <stdlib.h>

int is_divider(char c)
{
    if(c == 34 || c == ' ')
    	return (1);
    return (0);
}

static int	ft_count_numbers(char *str)
{
	int		num_num;
	char	*aux;

	num_num = 0;
	aux = str;
	while (*aux != '\0')
	{
		while (*aux != '\0' && is_divider(*aux) == 1)
			aux++;
		if (*aux != '\0')
			num_num++;
		while (*aux != '\0' && is_divider (*aux) != 1)
			aux++;
	}
	return (num_num);
}

int main(int argc, char **argv)
{
    int numbers;
	int	i;

    i = 1;
    while (i < argc)
    {
        numbers = ft_count_numbers(argv[i]);
		printf("%d\n", numbers);
        i++;
    }
    return (numbers); 
}





/*
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
}*/
/*
int	main(void):w
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
*/