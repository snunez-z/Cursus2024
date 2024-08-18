/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:54:39 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/14 15:40:53 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space( char	ch)
{
		if (ch == ' ' || (ch >= 9 && ch <= 13))
			return (1);
		else
			return (0);
}

int	main (int argc, char	**argv)
{
	int	i;
	char	*str;
	
	if (argc == 2 )
	{
		i = 0;
		str = argv[1];
		while (is_space (str[i]) == 1)
			i++;
		while (str[i] != '\0')
		{
			while (is_space (str[i]) == 0 && str[i] != '\0')
			{
				write (1,&str[i], 1);
				i++;
			}	
			while (is_space (str[i]) == 1 && str[i] != '\0')
				i++;
			if (str[i] != '\0')
				write(1, " ", 1);
		}
	}	
	write (1, "\n", 1);	
	return (0);
}

