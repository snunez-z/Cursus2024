/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:25:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/12 12:49:22 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char	*str);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcpy(char	*dest, char	*src, size_t size);
size_t	ft_strlcat(char	*dest, char	*src, size_t size);
int		ft_strncmp(char	*s1, char	*s2, size_t n);
char	*ft_strnstr(char	*s1, char	*s2, size_t n);
char	*ft_strrchr(char	*s1, int c);
int		ft_atoi(char	*str);
void	*ft_memset(void *src, int c, size_t length);
void	ft_bzero(void	*src, size_t length);;
void	*ft_memcpy(void	*dest, const char	*src, size_t n);
void	*ft_memmove(void *dest, const void	*src, size_t len);
