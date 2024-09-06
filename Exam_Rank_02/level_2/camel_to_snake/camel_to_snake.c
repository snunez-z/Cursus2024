/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:29:40 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/31 14:11:48 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int	i;
	
	if (argc == 2)
	{
		str = argv [1];
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= 'A' && str[i] <= 'Z' )
			{
				str[i] = str[i] + ('a' - 'A');
				if (i > 0)
					write (1, "_", 1);
			}
			write (1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
