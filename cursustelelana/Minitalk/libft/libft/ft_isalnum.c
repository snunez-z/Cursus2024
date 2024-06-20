/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:51:10 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/11 18:31:21 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
/*#include <stdio.h>*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int	main(void)
{
	int	c;

	c = ft_isalnum ('9');
	printf("%d\n", c);
	c = ft_isalnum ('G');
	printf("%d\n", c);
	c = ft_isalnum ('!');
	printf("%d\n", c);
	c = ft_isalnum ('?');
	printf("%d\n", c);
	return (0);
}*/
