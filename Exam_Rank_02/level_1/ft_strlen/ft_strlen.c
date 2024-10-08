/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:50:16 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/18 13:40:15 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen (char *str)
{
    int index;

    index = 0;
    while (str[index] != '\0')
    	index++;
    return (index);
}
/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_strlen ("Hola amiga"));
    return (0);
}*/

