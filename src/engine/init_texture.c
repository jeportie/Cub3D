/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:12:14 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 11:15:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/error.h"

int	init_wall_texture(t_data *data)
{
	int		width;
	int		height;
	int		i;

	i = 0;
	while (i < 4)
	{
		data->walls[i].img_ptr = mlx_xpm_file_to_image(data->mlx,
				data->parse.config.textures[i], &width, &height);
		if (!data->walls[i].img_ptr)
		{
			ft_dprintf(2, ERR_MLX_TEX, data->parse.config.textures[i]);
			return (1);
		}
		data->walls[i].addr = mlx_get_data_addr(data->walls[i].img_ptr,
				&data->walls[i].bpp, &data->walls[i].line_len,
				&data->walls[i].endian);
		i++;
	}
	return (0);
}
