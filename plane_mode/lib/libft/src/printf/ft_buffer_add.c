/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:03:11 by jeportie          #+#    #+#             */
/*   Updated: 2024/12/13 13:04:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

/*
void	ft_buffer_help(t_buffer *buf_info, char c)
{
	if ((size_t)buf_info->index < buf_info->max_size -1)
	{
		buf_info->buffer[buf_info->index++] = c;
		buf_info->nb_printed++;
	}
	else
	{
		if (buf_info->error == NOERR)
			buf_info->error = ERNOWRITE;
		return ;
	}
}

void	ft_buffer_add(t_buffer *buf_info, char c)
{
	if (buf_info->error)
		return ;
	if (buf_info->buf_fd == -1)
		ft_buffer_help(buf_info, c);
	else
	{
		if (buf_info->index >= BUFFER_SIZE)
		{
			buf_info->buf_last = buf_info->buffer[buf_info->index - 1];
			if (!ft_buffer_flush(buf_info))
			{
				buf_info->error = ERNOWRITE;
				return ;
			}
		}
	}
	buf_info->buffer[buf_info->index] = c;
	buf_info->index++;
}
*/

void	ft_buffer_add(t_buffer *buf_info, char c)
	{
	if (buf_info->error)
		return ;
	if (buf_info->buf_fd == -1)
	{
		buf_info->nb_printed++;
		if ((size_t)buf_info->index < buf_info->max_size - 1)
		{
			buf_info->buffer[buf_info->index] = c;
			buf_info->index++;
		}
		return ;
	}
	else
	{
		if (buf_info->index >= BUFFER_SIZE)
		{
			if (!ft_buffer_flush(buf_info))
			{
				buf_info->error = ERNOWRITE;
				return ;
			}
		}
		buf_info->buffer[buf_info->index] = c;
		buf_info->index++;
	}
}
