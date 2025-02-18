/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:35:58 by jeportie          #+#    #+#             */
/*   Updated: 2024/11/12 18:53:14 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# define ERROR -1

typedef struct s_buffer
{
	char	*buffer;
	int		index;
	int		nb_printed;
	int		error;
	char	buf_last;
	int		buf_fd;
	size_t	max_size;
}			t_buffer;

typedef struct s_format_spec
{
	int			width;
	int			precision;
	int			flag_minus;
	int			flag_zero;
	int			flag_hash;
	int			flag_space;
	int			flag_plus;
	char		type;
	int			error;
}				t_format_spec;

typedef enum e_error
{
	NOERR,
	ERNOWRITE,
	ERNOMEM,
	ERNOFORMAT,
}	t_error;

/* PRINTF */
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);

/* BUFFER */
void			ft_buffer_add(t_buffer *buf_info, char c);
int				ft_buffer_flush(t_buffer *buf_info);
void			ft_check_flush(t_buffer *buf_info);

/* Utils */
int				ft_isflag(char c);
int				ft_isconvert_spec(char c);
void			ft_perror(t_error error);

/* Parse */
t_format_spec	ft_parse_format(const char **format);
void			ft_parse_flags(const char *format, t_format_spec *spec);
int				ft_check_format(t_format_spec *spec);
int				ft_process_format_specifier(const char **format, va_list args,
					t_buffer *buf_info);

/* Manip functions */
void			ft_apply_width(t_format_spec spec, t_buffer *buf_info,
					int content_len);
void			ft_apply_precision(t_format_spec spec,
					char **formatted_content);
void			ft_handle_hash_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
void			ft_handle_space_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
void			ft_handle_plus_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
void			ft_handle_char(t_format_spec spec, va_list args,
					t_buffer *buf_info);
void			ft_handle_string(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_pointer(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_int(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_hexadecimal(t_format_spec spec, va_list args,
					t_buffer *buf_info);

#endif /*PRINTF_H*/
