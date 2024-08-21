/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:57:46 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/21 15:40:22 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char    **ft_split(char *str)
{



	return (split);
}

int	main (void)
{
	int	i;
	char	**split;

	i = 0;
	split = ft_split ("  Hola    amiga mia");
	while (split[i] != 0)
	{
		printf("%s\n", split [i]);
		i++;
	}
	return (0);
}

