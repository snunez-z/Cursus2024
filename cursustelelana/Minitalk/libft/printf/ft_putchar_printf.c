/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:59:32 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/18 08:29:59 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar_printf(char c)
{
	return (write (1, &c, 1));
}
/*
int	main(void)
{
	char	c;
	
    c = ft_putstr_printf('i');
	write (1, "\n", 1);
	return (0);
}*/
