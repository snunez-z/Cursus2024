/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:54:00 by snunez-z          #+#    #+#             */
/*   Updated: 2025/01/09 13:58:11 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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
	long	value;

	if (*str == '\0')
	{
		*p_error = 1;
		return (0);
	}
	value = 0;
	while (*str >= '0' && *str <= '9' && value <= ((long)INT_MAX + 1))
	{
		digit = (*str - '0');
		value = (value * 10) + digit;
		str++;
	}
	if (*str != '\0')
		*p_error = 1;
	else
		*p_error = 0;
	return (value);
}

int	su_atoi(const char *str, int *p_error)
{
	long	value;
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
	if (*p_error == 1)
		return (0);
	if (is_negative)
		value = (value * -1);
	if (value < INT_MIN || value > INT_MAX)
		*p_error = 1;
	return (value);
}
