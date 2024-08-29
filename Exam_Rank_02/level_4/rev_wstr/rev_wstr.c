/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:06:20 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 15:07:08 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	*str;
		int	i;
		int	start;
		int	end;


		str = argv [1];
		i = 0;
		while (str[i] != '\0')
			i++;
		while (i >= 0)
		{
			i--;
			end = i;
			while (str[i] != ' ' && i >= 0)
				i--;
			start = i + 1;
			write (1, &str [start], end - start + 1);
			if ( start > 0)
				write (1, " ", 1);
		}

	}
	write(1, "\n", 1);
	return (0);
}

