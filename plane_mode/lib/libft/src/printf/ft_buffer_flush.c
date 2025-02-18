/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_flush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:03:39 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:37:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

int	ft_buffer_flush(t_buffer *buf_info)
{
	int	written;

	int (total_written) = 0;
	if (buf_info->buf_fd == -1)
	{
		buf_info->index = 0;
		return (1);
	}
	while (total_written < buf_info->index)
	{
		written = write(buf_info->buf_fd, &buf_info->buffer[total_written],
				buf_info->index
				- total_written);
		if (written <= 0)
		{
			buf_info->nb_printed += total_written;
			buf_info->index = 0;
			buf_info->error = ERNOWRITE;
			return (0);
		}
		total_written += written;
	}
	buf_info->nb_printed += total_written;
	buf_info->index = 0;
	return (1);
}
