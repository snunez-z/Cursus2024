/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:19:53 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 15:29:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	char *str;
	int	i;

	if (argc == 2)
	{
		str = argv [1];
		i = 0;
		while (str [i] != '\0')
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = (str[i] - 'A' + 13) % 26 + 'A';
			else if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = (str[i] - 'a' + 13) % 26 + 'a';
			write (1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}


/*
int	main(int argc, char **argv)
{
	char	*str;
	int	i;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i] != '\0')
		{	
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 13;
				if (str[i] > 'Z')
					str[i]-= 26;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] += 13;
				if (str[i] > 'z')
					str[i] -= 26;
			}
			write(1, &str[i], 1);
			i++;
		}
	
	}	
	write (1, "\n", 1);
	return (0);
}
*/
