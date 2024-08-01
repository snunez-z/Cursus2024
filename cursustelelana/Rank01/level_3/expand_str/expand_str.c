/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:55:11 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:55:14 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>*/

#include <unistd.h>

int	is_space (char ch)
{
	
	if (ch == ' ' || ch == '\t')
	   return (1);
	else
		return (0);	
}

int main(int argc, char **argv)
{
	int	i;
	char	*str;

if (argc == 2)
{	
	i = 0;
	str = argv[1];
	while (is_space (str[i]) == 1)
		i++;
	while (str[i] != '\0')
	{
		while (is_space (str[i]) == 0 && str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
		while (is_space (str[i]) == 1 && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			write(1, "   ", 3);
	}
}
	write(1, "\n", 1);
	return (0);
}
