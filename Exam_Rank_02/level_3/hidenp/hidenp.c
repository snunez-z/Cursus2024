/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:57:14 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:57:22 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;
	
	if (argc < 3 || argv[1][0] == 0)
	{
		write(1, "\n", 1);
		return (-1);
	}

	i = 0;
	j = 0;
	s1 = argv[1];
	s2 = argv[2];
	while(s1[i] != 0)
	{
		while(s2[j] != s1[i] && s2[j] != 0)
			j++;
		if (s2[j] == 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		else
		{
			i++;
			j++;
		}
	}
	write(1, "1\n", 2);
	return (0);
}

