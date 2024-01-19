/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:25:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/19 09:04:35 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char	*str);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t size);
size_t	ft_strlcat(char	*dest, const char	*src, size_t size);
int		ft_strncmp(char	*s1, char	*s2, size_t n);
char	*ft_strnstr(char	*s1, char	*s2, size_t n);
char	*ft_strrchr(char	*s1, int c);
int		ft_atoi(char	*str);
void	*ft_memset(void *src, int c, size_t length);
void	ft_bzero(void	*src, size_t length);
void	*ft_memcpy(void	*dest, const char	*src, size_t n);
void	*ft_memmove(void *dest, const void	*src, size_t len);
char	*ft_strdup(const char	*str);
void	*ft_calloc(size_t quantity, size_t size_of_each_element);
void	*ft_memchr(const void	*s, int c, size_t n);
int		ft_memcmp(const void	*s1, const void	*s2, size_t n);
char	*ft_strchr(const char	*str, int c);
char	*ft_substr(const char	*str, unsigned int start, size_t len);
char	*ft_strtrim(const char	*str, const char	*set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char	*str, int fd);

#endif
