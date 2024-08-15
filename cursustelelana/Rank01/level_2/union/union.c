/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:52:51 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/14 13:40:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;

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
