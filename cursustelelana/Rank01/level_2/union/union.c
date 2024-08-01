/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:52:51 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:52:54 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
#include <unistd.h>

int	is_repeated(char *str, char ch, int end_pos)
{
	int	index;
    
	index= 0;
	while (str[index] != '\0' && index < end_pos)
	{
		if (str[index] == ch)
			return (1);
		index++;
	}
	return (0);
}

int	search_char(char *str, char ch)
{
	while (*str != '\0')
	{
		if(*str == ch)
			return (1);
		str++;
	}
	return (0);
}

int main (int argc, char	**argv)
{
	char	*str1;
	char	*str2;
	int	i1;
	int	i2;

	if (argc == 3)
	{
		i = 0;
		str1 = argv[1];
		str2 = argv[2];
		while (str1[i] !='\0')
		{
			if (is_repeated (str1,str1[i],i) == 0)
				write (1, &str1[i], 1);
			i++;
		}
		i = 0;
		while (str2[i] != '\0')
		{
			if (is_repeated (str2, str2[i], i) == 0 && search_char (str1, str2[i]) == 0)
				write (1,&str2[i], 1);
			i++;
		}
	}	
	write (1,"\n", 1);
	return (0);	
}
