/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:15:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/31 08:16:26 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const	char *str)
{
	int	value;
	int	is_negative;
		
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	is_negative = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = 1;
		else
			is_negative = 0;
		str++;
	}
	value = 0;
	while (*str != '\0')
	{
		value = (value * 10) + (*str - '0');
		str++;
	}	
	if (is_negative == 1)
		value = value * -1; 
	return (value);
}
/*
int	main(void)
{
	int	value;
	value = ft_atoi ("123");
	printf("%d\n", value);
	value = ft_atoi ("-123");
	printf("%d\n", value);
	value = ft_atoi ("   123");
	printf("%d\n", value);
	value = ft_atoi ("+123");
	printf("%d\n", value);
	value = ft_atoi ("-123");
	printf("%d\n", value);

}*/
