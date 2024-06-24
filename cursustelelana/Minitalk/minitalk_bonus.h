/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:21:22 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/24 14:22:01 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H

# define MINITALK_BONUS_H

typedef struct s_server
{
	char	signals_received [8];
	int		num_signal;

}	t_server;

typedef struct s_client
{
	int	*signals;
	int	num_signals;
	int	signal_index;
}	t_client;

#endif
