/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:28:27 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 14:28:45 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main (int argc, char	**argv)
{
	int	i;
	char	*str;

	if (argc == 2)
	{
		i = 0;
		str = argv [1];
		while (str[i] != '\0')
		{	
			if (str [i] >= 'A' && str [i] <= 'Z')
				str[i] = (str[i] - 'A' + 1) % 26 + 'A';
			else if (str [i] >= 'a' && str [i] <= 'z')
				str [i] = (str[i] - 'a' + 1) % 26 + 'a';
			write (1, &str[i], 1);
			i++;
		}
	}	
	write (1, "\n", 1);
	return (0);
}

/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *s)
{
	while (*s)
	{
		if ((*s >= 'A' && *s <= 'Y') || (*s >= 'a' && *s <= 'y'))
			ft_putchar(*s + 1);
		else if (*s == 'Z' || *s == 'z')
			ft_putchar(*s - 25);
		else
			ft_putchar(*s);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	ft_putchar('\n');
	return (0);
} */
