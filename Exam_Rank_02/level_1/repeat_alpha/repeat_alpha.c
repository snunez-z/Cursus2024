/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:56:58 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 13:57:30 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar( char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}
void	repeat_alpha(char	*str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			ft_putchar (*str, (*str + 1) - 'a');
		else if (*str >= 'A' && *str <= 'Z')
			ft_putchar(*str, (*str + 1) - 'A');
		else
			write (1, str, 1);
		str++;
	}
}

int	main (int argc, char	**argv)
{
	if (argc == 2)
		repeat_alpha (argv [1]);
	write (1, "\n", 1);
	return (0);
}
