/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:49:49 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/23 10:03:30 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - ('a' - 'A');
	}
	return (c);
}
/*
int	main(void)
{
	char	c;
	char	lc;

	c = 'A';
	lc = ft_toupper(c);
	printf("%c\n", lc);
	return (0);
}*/
