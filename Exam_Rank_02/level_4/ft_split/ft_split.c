/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:57:46 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/22 15:45:54 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
//#include <stdio.h>

char	**ft_split (char	*str)
{
	int	i_str;
	int	i_words;
	int	i2_words;
	char	**words;

	words = (char **)malloc (256 * sizeof (char *));
	if (words == NULL)
		return (NULL);
	i_str = 0;
	i_words = 0;
	while( str[i_str] == ' ' || str[i_str] == '\t' || str[i_str] == '\n')
			i_str++;
	while (str[i_str] != '\0')
	{
		i2_words = 0;
		words [i_words] = (char *) malloc (sizeof (char) * 4096);
		if (!words [i_words])
			return (NULL);
		while(str[i_str] != ' ' && str[i_str] != '\t' && str[i_str] != '\n')
		{	
			words[i_words][i2_words] = str[i_str];
			i_str++;
			i2_words++;	
		}	

		while(str[i_str] == ' ' || str[i_str] == '\t' || str[i_str] == '\n')
			i_str++;
		words[i_words][i2_words] = '\0';
		i_words++;
	}
	words[i_words] = NULL;
	return (words);
}

/* to chek the function
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
}*/
