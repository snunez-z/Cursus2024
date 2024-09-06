/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:26:30 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 08:26:42 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>i

int	main(int argc, char	**argv)
{
	
	char	*str;
	
	if (argc == 2)
	{
		str = argv [1];	
		while (*str == ' ' || *str == '\t')
			str++;
		while (*str != ' ' && *str != '\t' && *str != '\0')
		{	
			write (1, str, 1);
			str++;
		}
	}	
	write(1, "\n", 1);
	return (0);
}
