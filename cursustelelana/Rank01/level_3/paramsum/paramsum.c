/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:58:28 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:58:31 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	putnbr (int	num)
{
	char digit;

	digit = (num % 10) + '0';
	if (num > 10 )
		putnbr (num / 10);
	write (1 , &digit, 1);
}

int main(int argc, char **argv)
{
	putnbr(argc-1);
}	

