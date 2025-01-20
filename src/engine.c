/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:10:44 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/20 23:18:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"

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
	x = 0;
	while (y < WINDOW_HEIGHT)
	{
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
	data->img.img_ptr = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img.img_ptr)
	{
		ft_dprintf(2, "Error: mlx_new_image() failed.\n");
		exit(1);
	}
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp,
			&data->img.line_len,
			&data->img.endian);
	if (!data->img.addr)
	{
		ft_dprintf(2, "Error: mlx_get_data_addr() failed.\n");
		exit(1);
	}
	return (0);
}
