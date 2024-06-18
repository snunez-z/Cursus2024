/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:28:37 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/18 08:30:05 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int printf_convertion_X (va_list args, int count)
{
	char			*str;
	unsigned long 	ld;
	int				w_check;

	ld = va_arg(args, unsigned int);
	str = ft_htoa(ld);
	if (str)
	{
		count = count + ft_strlen(str);
		w_check = ft_putstr_printf(str);
		free(str);
		if(w_check < 0)
			return (-1);
	}
	return( count);
}
