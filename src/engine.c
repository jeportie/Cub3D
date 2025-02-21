/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:10:44 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/05 19:54:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"
#include "../include/error.h"

double	get_time_in_seconds(struct timespec ts)
{
	return ((double)ts.tv_sec + (double)ts.tv_nsec / 1e9);
}

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

int	init_texture(t_data *data)
{
	int	width;
	int	height;

	data->texture.img_ptr
		= mlx_xpm_file_to_image(data->mlx, TEXTURE, &width, &height);
	if (!data->texture.img_ptr)
	{
		ft_dprintf(2, "Error: could not load texture from %s\n", TEXTURE);
		return (1);
	}
	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		ft_printf("Warning: texture size (%d x %d) is not equal "
			"to TILE_SIZE (%d x %d)\n", width, height, TILE_SIZE, TILE_SIZE);
	}
	data->texture.addr = mlx_get_data_addr(data->texture.img_ptr,
			&data->texture.bpp, &data->texture.line_len, &data->texture.endian);
	return (0);
}
