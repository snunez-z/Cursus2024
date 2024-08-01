/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:10 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 14:56:31 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{

	int	i;

	if (argc == 4 && argv[2][1] == '\0' && argv[3][1] == '\0')
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == argv [2][0])
				argv[1][i] = argv[3][0];
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

