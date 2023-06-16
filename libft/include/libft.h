/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:57:46 by bmoudach          #+#    #+#             */
/*   Updated: 2023/05/11 19:29:56 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stddef.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>

int		ft_isalnum(int argument);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int arg);
int		ft_memcmp(const void *pointer1, const void *pointer2, size_t size);
int		ft_atoi(const char *str );
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup( const char *src );
char	*ft_itoa(int nb);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memmove(void *dst, const void *src, size_t num);
void	*ft_memcpy(void *dst, const void *src, size_t num);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc( size_t nitems, size_t size );
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);

#endif
