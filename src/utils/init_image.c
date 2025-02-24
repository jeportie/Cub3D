/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:11:41 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/23 17:12:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"
#include "../../include/error.h"

int	init_image(t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		data->img[i].img_ptr
			= mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		if (!data->img[i].img_ptr)
		{
			ft_dprintf(2, ERR_MLX_IMAGE);
			exit(1);
		}
		data->img[i].addr = mlx_get_data_addr(data->img[i].img_ptr,
				&data->img[i].bpp,
				&data->img[i].line_len,
				&data->img[i].endian);
		if (!data->img[i].addr)
		{
			ft_dprintf(2, ERR_MLX_DATA);
			exit(1);
		}
		i++;
	}
	data->current_img = 0;
	return (0);
}
