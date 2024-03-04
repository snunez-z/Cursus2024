/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:46:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 17:47:33 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == ' ' || *str == 11)
		return (1);
	else
		return (0);
}

static int	convert_to_int(const char	*str)
{
	char	digit;
	int		value;

	value = 0;
	while (ft_isdigit (*str))
	{
		digit = (*str - '0');
		value = (value * 10) + digit;
		str++;
	}
	return (value);
}

int	ft_atoi(const char	*str)
{
	int		value;
	char	is_negative;		

	while (ft_isspace(str))
	{
		str++;
	}
	is_negative = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = 1;
		else
			is_negative = 0;
		str++;
	}
	value = convert_to_int (str);
	if (is_negative)
		value = (value * -1);
	return (value);
}
