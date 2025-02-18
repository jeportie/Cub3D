/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:43:20 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 14:43:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	t_buffer	buf_info;
	char		buffer[BUFFER_SIZE];

	ft_memset(&buf_info, 0, sizeof(t_buffer));
	buf_info.buffer = buffer;
	buf_info.buf_fd = 1;
	if (fd != -1)
		buf_info.buf_fd = fd;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_process_format_specifier(&format, args, &buf_info) == -1)
				return (-1);
		}
		else
			ft_buffer_add(&buf_info, *format);
		format++;
	}
	va_end(args);
	ft_check_flush(&buf_info);
	return (buf_info.nb_printed);
}
