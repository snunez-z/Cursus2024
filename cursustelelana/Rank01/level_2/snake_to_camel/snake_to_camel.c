/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:52:10 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:52:15 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$*/

#include <unistd.h>

int	is_lower(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	else
		return (0);
}


int	main(int argc, char **argv)
{
	char	*str;
	int	i;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i] == '_' || str[i] == '\t')
			i++;
		while (str [i] != '\0')
		{
			if (str[i] != '_')
			{
				if (str[i - 1] == '_' && is_lower(str [i]))
					str[i] = str[i] - ( 'a' - 'A');				
				write (1, &str[i], 1);
			}
			i++;
		}  	
	}	
	write (1, "\n", 1);
}


