/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_space_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:25:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:38:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_handle_space_flag(t_format_spec spec, int content,
		t_buffer *buf_info)
{
	if (spec.flag_space && !spec.flag_plus && content >= 0)
	{
		if (spec.type == 'u')
		{
			if (!spec.width)
				return ;
		}
		ft_buffer_add(buf_info, ' ');
	}
}
