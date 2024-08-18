/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:14:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:35:52 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strchr(const char	*s, int c)
{

	while (*s != '\0')
	{
		if (*s != c)
			s++;
		else
			return (1);
	}
		return (0);
}

int	is_repeated (char	*str, int pos)
{
	int i;
	char ch;

	ch = str[pos];
	i = 0;
	while (i < pos)
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);	
}

int main(int argc, char **argv)
{
	int i;
	char *str;
	char *str2;

	if (argc == 3)
	{
		i = 0;
		str = argv[1];
		str2 = argv[2];
		while (str[i] != '\0')
		{
			if (ft_strchr (str2, str[i]) == 1 && is_repeated (str, i) == 0)
				write (1, &str[i], 1);
			i++;
		}
		
	}
	write(1 , "\n", 1);
	return (0);
}
