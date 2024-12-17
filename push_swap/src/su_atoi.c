/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:54:00 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/17 15:34:09 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "push_swap.h"

static int	ft_isspace(const char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == ' ' || *str == 11)
		return (1);
	else
		return (0);
}

static long	convert_to_int(const char	*str, int *p_error)
{
	char	digit;
	long		value;

	value = 0;
	while (*str >= '0' && *str <= '9' && value <= (INT_MAX + 1))
	{
		digit = (*str - '0');
		value = (value * 10) + digit;
		str++;
	}

	// * Hemos salido antes de llegar al final del número. Eso es que nos hemos encontrado un
	// carácter que no es un dígito o nos hemos pasado de INT_MAX + 1
	if (*str != '\0')
		*p_error = 1;
	// * En caso contrario... pues todo ha ido bien => tenemos que poner "false" en p_error
	else
		*p_error = 0;
	return (value);
}
int su_atoi(const char *str, int *p_error)
{
	long    value;
	char	is_negative;		

	while (ft_isspace(str))
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
	value = convert_to_int (str, p_error);
	if(*p_error == 1)
		return (0);
	if (is_negative)
		value = (value * -1);
	if (value < INT_MIN || value > INT_MAX)
		*p_error = 1;
	return (value);
}

