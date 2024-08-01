/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:27:22 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 16:27:36 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char	**argv)
{
	int	i;
	char	*str;
	
	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = 'Z' - str[i] + 'A';
			else if(str[i] >= 'a' && str[i] <= 'z')
				str[i] = 'z' - str[i] + 'a';
			write (1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
