/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:00:02 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/11 15:25:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space (char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	return (0);
}


#include <unistd.h>

int	main (int argc, char	**argv)
{
	int	i;
	int	j;

	if (argc == 1)
	{
		write (1, "\n", 1);
		return(-1);
	}	
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((j == 0 || is_space (argv [i][j - 1])) && (argv [i][j] >= 'a' && argv[i][j] <= 'z'))
				argv[i][j] = argv[i][j] - ('a' - 'A');
			else if (j > 0 && !is_space (argv [i][j - 1]) && argv[i][j] >= 'A' && argv [i][j] <= 'Z')
				argv[i][j] = argv [i][j] - ('A' - 'a');
			write (1, &argv[i][j], 1);
			j++;
		}
		i++;
	}	
	write(1, "\n", 1);
	return (0);
}
