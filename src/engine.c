/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:10:44 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 13:06:36 by jeportie         ###   ########.fr       */
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

	data->texture_n.img_ptr
		= mlx_xpm_file_to_image(data->mlx, TEXTURE_N, &width, &height);
	if (!data->texture_n.img_ptr)
	{
		ft_dprintf(2, ERR_MLX_TEX, TEXTURE_N);
		return (1);
	}
	data->texture_s.img_ptr
		= mlx_xpm_file_to_image(data->mlx, TEXTURE_S, &width, &height);
	if (!data->texture_s.img_ptr)
	{
		ft_dprintf(2, ERR_MLX_TEX, TEXTURE_S);
		return (1);
	}
	data->texture_e.img_ptr
		= mlx_xpm_file_to_image(data->mlx, TEXTURE_E, &width, &height);
	if (!data->texture_e.img_ptr)
	{
		ft_dprintf(2, ERR_MLX_TEX, TEXTURE_E);
		return (1);
	}
	data->texture_o.img_ptr
		= mlx_xpm_file_to_image(data->mlx, TEXTURE_O, &width, &height);
	if (!data->texture_o.img_ptr)
	{
		ft_dprintf(2, ERR_MLX_TEX, TEXTURE_O);
		return (1);
	}

	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		ft_printf(WARN_NOEQUAL, width, height, TILE_SIZE, TILE_SIZE);
	}

	data->texture_n.addr = mlx_get_data_addr(data->texture_n.img_ptr,
			&data->texture_n.bpp, &data->texture_n.line_len, &data->texture_n.endian);
	data->texture_s.addr = mlx_get_data_addr(data->texture_s.img_ptr,
			&data->texture_s.bpp, &data->texture_s.line_len, &data->texture_s.endian);
	data->texture_e.addr = mlx_get_data_addr(data->texture_e.img_ptr,
			&data->texture_e.bpp, &data->texture_e.line_len, &data->texture_e.endian);
	data->texture_o.addr = mlx_get_data_addr(data->texture_o.img_ptr,
			&data->texture_o.bpp, &data->texture_o.line_len, &data->texture_o.endian);
	return (0);
}
