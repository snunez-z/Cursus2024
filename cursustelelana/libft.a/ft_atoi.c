/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:46:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/10 17:15:17 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_atoi(char	*str)
{
	int	digit;
	int	value;

	value = 0;
	while (*str != '\0')
	{
		digit = *str - '0';
		value = (value * 10) + digit;
		str++;
	}
	return (value);
}
/*
int	main(void)
{
	int	value;
	
	value = ft_atoi("123");
	printf("%d\n", value);
	value = ft_atoi("15675823");
	printf("%d\n", value);
	value = ft_atoi("56");
	printf("%d\n", value);
}*/
