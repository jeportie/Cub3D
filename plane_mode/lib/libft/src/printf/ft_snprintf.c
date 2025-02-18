/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:45:45 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/06 12:34:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_loop_helper(const char *format, va_list args, t_buffer *buf_info)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_process_format_specifier(&format, args, buf_info) == -1)
				return (0);
		}
		else
			ft_buffer_add(buf_info, *format);
		format++;
	}
	return (1);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list		args;
	t_buffer	buf_info;

	if (!str || !format)
		return (-1);
	ft_memset(&buf_info, 0, sizeof(t_buffer));
	buf_info.buffer = str;
	buf_info.max_size = size;
	buf_info.buf_fd = -1;
	va_start(args, format);
	if (!ft_loop_helper(format, args, &buf_info))
		return (-1);
	va_end(args);
	if (size > 0)
	{
		if ((size_t)buf_info.index < size)
			buf_info.buffer[buf_info.index] = '\0';
		else
			buf_info.buffer[size - 1] = '\0';
	}
	return (buf_info.nb_printed);
}
