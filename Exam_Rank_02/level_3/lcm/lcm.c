/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:57:59 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:58:02 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int mult;

	if (a == 0 || b == 0)
		return (0);
	mult = 1;
	while((a * mult) % b != 0)
		mult++;
	return (a*mult);
}
