/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_porcentaje.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:10:16 by snunez-z          #+#    #+#             */
/*   Updated: 2024/03/12 11:12:35 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	printf_conv_porcentaje(int count)
{
	int	w_check;

	w_check = ft_putchar_printf('%');
	if (w_check < 0)
		return (-1);
	count++;
	return (count);
}
