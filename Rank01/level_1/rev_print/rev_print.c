/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:11:23 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 14:11:35 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main (int argc, char **argv)
{
	char	*str;
	int	index;

	index = 0;
	str = argv[1];
	if (argc == 2)
	{
		while (str [index] != '\0')
			index++;
		while ( index > 0)
		{
			write (1, (&str [index - 1]), 1);
			index --;
		}
	}	
	write (1, "\n", 1);
	return (0);
}
