/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:07:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 15:08:05 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main (int argc, char **argv)
{
	if (argc > 1 && argv[1][0] != '\0')
	{
		int	i;
		char	*str;
		int	start;
		int	end;

		str = argv[1];
		i = 0;
		while (str [i] == ' ' || str[i] == '\t')
			i++;
		start = i;
		while (str [i] != ' ' && str[i] != '\t' && str [i] != '\0')
			i++;
		end = i;
		while (str [i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] != '\0')
		{
			while (str [i] != ' ' && str[i] != '\t' && str [i] != '\0')
			{
				write (1, &str[i], 1);
				i++;
			}
			write (1, " ", 1);
			while (str [i] == ' ' || str[i] == '\t' )
				i++;
		}
		write (1, &str[start], end - start);
	}
	write(1,"\n", 1);
	return(0);
}

