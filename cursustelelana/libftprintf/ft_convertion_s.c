/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:16:48 by snunez-z          #+#    #+#             */
/*   Updated: 2024/03/12 11:20:49 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	printf_convertion_s(va_list args, int count)
{
	char	*str;
	int		w_check;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		w_check = ft_putstr_printf("(null)");
		if (w_check < 0)
			return (-1);
		count = count + 6;
	}
	else
	{
		w_check = ft_putstr_printf(str);
		if (w_check < 0)
			return (-1);
		count = count + ft_strlen(str);
	}
	return (count);
}
