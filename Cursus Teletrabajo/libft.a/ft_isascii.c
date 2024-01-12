/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:44:51 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/09 09:02:10 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	int c;

	c = ft_isascii ('b');
	printf("%d\n", c);
	c = ft_isascii ('5');
	printf("%d\n", c);
	c = ft_isascii (250);
	printf("%d\n", c);
	c = ft_isascii ('9850');
	printf("%d\n", c);
	return (0);
}*/
