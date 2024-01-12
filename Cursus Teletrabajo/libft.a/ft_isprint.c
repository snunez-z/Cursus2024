/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:09:22 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/09 10:02:53 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
int	main(void)
{
	int	c;

	c = ft_isprint(60);
	printf("%d\n", c);
	c = ft_isprint('A');
	printf("%d\n", c);
	c = ft_isprint(250);
	printf("%d\n", c);
	c = ft_isprint(158);
	printf("%d\n", c);
	return (0);
}*/
