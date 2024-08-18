/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:33:24 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/25 09:34:46 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H

# define MINITALK_H

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
