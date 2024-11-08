
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

static int	ft_count_numbers(size_t *list_num, size_t divider)
{
	size_t		num;
	size_t	*aux;

	num = 0;
	aux = list_num;
	while (*aux != '\0')
	{
		while (*aux != '\0' && *aux == divider)
			aux++;
		if (*aux != '\0')
			num++;
		while (*aux != '\0' && *aux != divider)
			aux++;
	}
	return (num);
}

static size_t	find_numbers_into_string(size_t *list_num, size_t **num, size_t divider)
{
	size_t	*from;
	size_t	*to;
	size_t	index;

	index = 0;
	from = list_num;
	while (*from != 0)
	{
		while (*from != '\0' && *from == divider)
			from++;
		if (*from != '\0')
		{
			to = from;
			while (*to != '\0' && *to != divider)
				to++;
			num[index] = su_substr(from, 0, to - from);
			if (num [index] == 0)
				return (0);
			from = to;
			index++;
		}
	}
	return (1);
}

static void	ft_free_reserved_memory(size_t **num)
{
	int	index;

	index = 0;
	while (num[index] != 0)
	{
		free (num [index]);
		index++;
	}
	free(num);
}

size_t	**su_split(size_t *list_num, char divider)
{
	size_t	**num;
	int		num_nums;

	if (list_num == 0)
		return (0);
	num_nums = ft_count_numbers((size_t *)list_num, divider);
	num = (size_t **) su_calloc(num_nums + 1, sizeof(size_t *));
	if (num)
	{
		if (find_numbers_into_string ((size_t *)list_num, num, divider) == 0)
		{
			ft_free_reserved_memory (num);
			return (0);
		}
	}
	return (num);
}

int	main(void)
{
	int		index;
	size_t	**split;

	split = su_split("50 10 20 5 7", ' ');
	index = 0;
	while (split[index] != 0)
	{
		printf("%ln\n", split[index]);
		index++;
	}
	return (0);
}

