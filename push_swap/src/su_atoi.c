/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:54:00 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/17 10:31:32 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (*str >= '0' && *str <= '9')
	{
		digit = (*str - '0');
		value = (value * 10) + digit;
		str++;
	}
	return (value);
}

int	su_atoi(const char	*str, int *p_error)
{
	long    value;
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
