/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:15:55 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/09 13:01:19 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c - ('A' - 'a');
	}
	return (c);
}

int	main(void)
{
	char	c;
	char	lc;

	c = 'A';
	lc = ft_tolower(c);
	printf("%c\n", lc);
	c = 'F';
	lc = ft_tolower(c);
	printf("%c\n", lc);
	return (0);
}
