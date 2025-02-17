/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:56:22 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:38:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_handle_string(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	char	*str;
	int		content_len;
	int		i;

	str = (char *)va_arg(args, char *);
	if (!str)
		str = "(null)";
	content_len = 0;
	while (str[content_len]
		&& (spec.precision < 0 || content_len < spec.precision))
		content_len++;
	i = 0;
	if (!spec.flag_minus)
		ft_apply_width(spec, buf_info, content_len);
	while (str[i] && i < content_len)
		ft_buffer_add(buf_info, str[i++]);
	if (spec.flag_minus)
		ft_apply_width(spec, buf_info, content_len);
}
