/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:52:10 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/02 11:51:45 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		while (str[i] == ' ' || str[i] == '\t')
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


