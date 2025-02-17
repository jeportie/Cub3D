/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:59:02 by jeportie          #+#    #+#             */
/*   Updated: 2024/11/04 17:29:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include "printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# define ERROR -1

/*	BOOL FUNCTIONS */
bool			ft_isspace(int c);
bool			ft_isalnum(int c);
bool			ft_isalpha(int c);
bool			ft_isascii(int c);
bool			ft_isdigit(int c);
bool			ft_isprint(int c);
bool			ft_isxdigit(int c);

/*	CONVERSION FUNCTIONS */
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);

char			*ft_itoa(int n);
char			*ft_utoa_base(unsigned int nbr, char *base);
char			*ft_ulltoa_base(unsigned long long nbr, char *base);
int				ft_nbr_len(unsigned long long nbr, int base_len);
int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);

char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);

size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);

//		Partie 2 - Fonctions supplementaires
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, const char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *S, char c);
size_t			ft_count_words(char *str, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* GNL */
char			*get_next_line(int fd);

/* UTILITIES */

void			ft_check_fd(int fd, const char *error_message);
void			ft_check_malloc(void *ptr, const char *error_message);
void			ft_check_pid(int pid);
char			*ft_getenv(char **envp, const char *name);
char			*ft_find_cmd_path(char **envp, const char *cmd);

#endif /*LIBFT_H*/
