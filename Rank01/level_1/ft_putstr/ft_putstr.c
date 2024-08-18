/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:17:50 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 09:19:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putstr (char *str)
{
    while (*str != '\0')
    {
        write (1, str, 1);
        str++;
    }
}
/*
int main (void)
{
   
    ft_putstr ("Hola buena amiga");
    write (1, "\n", 1);
}*/
