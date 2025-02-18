/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:43:10 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:11:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_prepare_int(t_format_spec spec, long long content,
		char **formatted_content, t_buffer *buf_info)
{
	if (spec.type == 'i' || spec.type == 'd')
		*formatted_content = ft_itoa((int)content);
	else if (spec.type == 'u')
		*formatted_content = ft_utoa_base((unsigned int)content, "0123456789");
	if (!*formatted_content)
	{
		buf_info->error = ERNOMEM;
		return (0);
	}
	if (spec.precision != -1)
		ft_apply_precision(spec, formatted_content);
	return (1);
}

static void	ft_process_int(t_format_spec spec, long long content,
		t_buffer *buf_info, char *formatted_content)
{
	int	formatted_len;
	int	i;

	formatted_len = ft_strlen(formatted_content);
	i = 0;
	if (!spec.flag_minus)
	{
		if (spec.flag_zero && formatted_content[0] == '-')
		{
			ft_buffer_add(buf_info, '-');
			i = 1;
		}
		ft_apply_width(spec, buf_info, formatted_len + (spec.flag_space
				|| spec.flag_plus));
	}
	ft_handle_space_flag(spec, content, buf_info);
	ft_handle_plus_flag(spec, content, buf_info);
	while (formatted_content[i])
		ft_buffer_add(buf_info, formatted_content[i++]);
	if (spec.flag_minus)
		ft_apply_width(spec, buf_info, formatted_len + (spec.flag_space
				|| spec.flag_plus));
}

int	ft_handle_int(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	char		*formatted_content;
	long long	content;

	formatted_content = NULL;
	if (spec.type == 'i' || spec.type == 'd')
		content = (int)va_arg(args, int);
	else if (spec.type == 'u')
		content = (unsigned int)va_arg(args, unsigned int);
	else
		content = 0;
	if (!ft_prepare_int(spec, content, &formatted_content, buf_info))
		return (0);
	ft_process_int(spec, content, buf_info, formatted_content);
	free(formatted_content);
	return (1);
}
