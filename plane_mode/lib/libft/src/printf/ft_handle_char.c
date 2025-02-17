/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:12:16 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:37:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_handle_char(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	char	c;
	int		content_len;

	c = (char)va_arg(args, int);
	content_len = 1;
	if (spec.flag_minus)
		ft_buffer_add(buf_info, c);
	ft_apply_width(spec, buf_info, content_len);
	if (!spec.flag_minus)
		ft_buffer_add(buf_info, c);
}
