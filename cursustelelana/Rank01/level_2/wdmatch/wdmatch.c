/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:53:38 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:53:41 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat -e
forty two$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$*/

#include <unistd.h>

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	is_possible(char *str1, char *str2)
{
	int	i;
	int j;
	i = 0;
	j = 0;
	while(str1[i] != '\0')
	{
		while (str2[j] != '\0' && str1[i] != str2[j])
			j++;
		if (str2[j] == '\0')
			return (0);
		if (str1[i] == str2[j])
			j++;
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (is_possible (argv[1], argv[2]) == 1)
			write (1, argv[1],ft_strlen(argv[1]));
	}
	write (1, "\n", 1);
	return (0);	
}
