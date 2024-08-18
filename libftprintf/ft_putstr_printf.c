/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:01:24 by snunez-z          #+#    #+#             */
/*   Updated: 2024/03/06 12:58:52 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putstr_printf(const char	*str)
{
	return (write (1, str, ft_strlen(str)));
}
/*
int	main(void)
{
	char	*str;
	
    str = "Susana";
	ft_putstr_printf(str);
	write (1, "\n", 1);
	return (0);
}*/
