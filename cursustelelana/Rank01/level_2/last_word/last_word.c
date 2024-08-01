/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:48:29 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 16:42:38 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main (int argc,	char	**argv)
{
	
	char	*str;
	int	i;
	
	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i] != '\0')
			i++;
		i--;
		while (str[i] == ' ' || (str [i] >= 9 && str [i] <= 13) && i >= 0)
			i--;
		while (str[i] != ' ' && !(str [i] >= 9 && str [i] <= 13))
			i--;
		i++;
		while (str[i] != '\0' && !(str [i] >= 9 && str [i] <= 13) && str[i] != ' ')
		{
			write (1, &str[i], 1);
			i++;	
		}	
	}
	write (1, "\n", 1);
	return (0);
}


