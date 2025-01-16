/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hash_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:39:26 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:37:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_handle_hash_flag(t_format_spec spec, int content, t_buffer *buf_info)
{
	if (spec.flag_hash && content)
	{
		ft_buffer_add(buf_info, '0');
		if (spec.type == 'X')
			ft_buffer_add(buf_info, 'X');
		if (spec.type == 'x')
			ft_buffer_add(buf_info, 'x');
	}
}
