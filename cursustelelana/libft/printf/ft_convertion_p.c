/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:36:52 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/18 08:30:05 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_convertion_p(va_list args, int count)
{
	void	*p;
	char	*str;

	p = va_arg(args, void *);
	if (ft_putstr_printf("0x") < 0)
		return (-1);
	str = ft_htoa_lower((unsigned long)p);
	if (!str)
	{
		free (str);
		return (-1);
	}
	count = count + 2 + ft_strlen (str);
	if (ft_putstr_printf(str) < 0)
	{
		free (str);
		return (-1);
	}
	free (str);
	return (count);
}
