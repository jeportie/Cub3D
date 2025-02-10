/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_engine_api.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:44:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 22:54:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_engine.h"

const t_graphic_engine_api	g_graphic_engine_methods = {
	.init = init_graphic_engine,
	.destroy = destroy_graphic_engine
};

int	put_pixel_to_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return (-1);
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	clear_image(t_image *img, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

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



t_graphic_engine	*create_graphic_engine(void);
int					init_graphic_engine(t_graphic_engine *graphic_engine);
int					destroy_graphic_engine(t_graphic_engine *graphic_engine);
