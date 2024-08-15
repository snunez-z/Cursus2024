/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:53:38 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/14 13:16:01 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	is_possible(char *str1, char *str2)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while(str1[i] != '\0')
	{
		while (str2[j] != '\0' && str1[i] != str2[j])
			j++;
		if (str2[j] == '\0')
			return (0);
		if (str1[i] == str2[j])
			j++;
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (is_possible (argv[1], argv[2]) == 1)
			write (1, argv[1],ft_strlen(argv[1]));
	}
	write (1, "\n", 1);
	return (0);	
}
