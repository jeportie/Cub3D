/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:18:44 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:11:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_prepare_hex_content(t_format_spec spec, unsigned int content,
		char **formatted_content, t_buffer *buf_info)
{
	if (spec.type == 'X')
		*formatted_content = ft_utoa_base(content, "0123456789ABCDEF");
	else if (spec.type == 'x')
		*formatted_content = ft_utoa_base(content, "0123456789abcdef");
	if (!*formatted_content)
	{
		buf_info->error = ERNOMEM;
		return (0);
	}
	if (spec.precision != -1)
		ft_apply_precision(spec, formatted_content);
	return (1);
}

static void	ft_process_formatted_hex(t_format_spec spec, unsigned int content,
		t_buffer *buf_info, char *formatted_content)
{
	int	formatted_len;
	int	i;

	formatted_len = ft_strlen(formatted_content);
	if (spec.flag_hash && content)
		formatted_len += 2;
	i = 0;
	if (!spec.flag_minus)
	{
		if (spec.flag_zero && spec.flag_hash)
			ft_handle_hash_flag(spec, content, buf_info);
		ft_apply_width(spec, buf_info, formatted_len);
	}
	if (!spec.flag_zero)
		ft_handle_hash_flag(spec, content, buf_info);
	while (i < formatted_len && formatted_content[i])
		ft_buffer_add(buf_info, formatted_content[i++]);
	if (spec.flag_minus)
		ft_apply_width(spec, buf_info, formatted_len);
}

int	ft_handle_hexadecimal(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	char			*formatted_content;
	unsigned int	content;

	formatted_content = NULL;
	content = va_arg(args, unsigned int);
	if (!ft_prepare_hex_content(spec, content, &formatted_content, buf_info))
		return (0);
	ft_process_formatted_hex(spec, content, buf_info, formatted_content);
	free(formatted_content);
	return (1);
}
