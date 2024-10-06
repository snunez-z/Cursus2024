/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:19:24 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 10:35:52 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

void	*util_calloc(size_t size);
void	*util_load_image(void *mlx, char *file_name);
void	util_destroy_image(void *mlx, void *image);
int		util_display_error(const char *message, int return_code);

#endif
