/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:53:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 20:13:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minimap.h"
#include "../include/engine.h"

char	g_map[MAP_SIZE + 1] = {
	"11111111"
	"10010001"
	"10010001"
	"10010011"
	"10000001"
	"10000001"
	"1P000001"
	"11111111"
};

int	compute_map_offset(t_data *data)
{
	int	map_pixel_width;
	int	map_pixel_height;

	map_pixel_width = MAP_WIDTH * TILE_SIZE;
	map_pixel_height = MAP_HEIGHT * TILE_SIZE;
	data->map_offset_x = (WINDOW_WIDTH - map_pixel_width) / 2;
	data->map_offset_y = (WINDOW_HEIGHT - map_pixel_height) / 2;
	if (data->map_offset_x < 0)
		data->map_offset_x = 0;
	if (data->map_offset_y < 0)
		data->map_offset_y = 0;
	return (0);
}

int	print_map(void)
{
	int	row;
	int	col;

	ft_printf("Map layout (0=floor, 1=wall, P=player):\n");
	row = 0;
	while (row < MAP_HEIGHT)
	{
		col = 0;
		while (col < MAP_WIDTH)
		{
			ft_printf("%c ", g_map[row * MAP_WIDTH + col]);
			col++;
		}
		ft_printf("\n");
		row++;
	}
	ft_printf("\n");
	return (0);
}

int	draw_tile(t_data *data, int row, int col, int base_color)
{
	int	py;
	int	px;
	int	x;
	int	y;
	int	color;

	py = 0;
	while (py < TILE_SIZE)
	{
		px = 0;
		while (px < TILE_SIZE)
		{
			x = data->map_offset_x + col * TILE_SIZE + px;
			y = data->map_offset_y + row * TILE_SIZE + py;
			color = base_color;
			if (py == 0 || py == TILE_SIZE - 1
				|| px == 0 || px == TILE_SIZE - 1)
				color = 0x666666;
			put_pixel_to_image(&data->img, x, y, color);
			px++;
		}
		py++;
	}
	return (0);
}

int	draw_map(t_data *data)
{
	int		row;
	int		col;
	char	tile;
	int		base_color;

	row = 0;
	while (row < MAP_HEIGHT)
	{
		col = 0;
		while (col < MAP_WIDTH)
		{
			tile = g_map[row * MAP_WIDTH + col];
			if (tile == '1')
				base_color = 0xFFFFFF;
			else
				base_color = 0x000000;
			draw_tile(data, row, col, base_color);
			col++;
		}
		row++;
	}
	return (0);
}

int	draw_square(t_data *data, int x_start, int y_start)
{
	int	row;
	int	col;
	int	draw_col;
	int	draw_row;

	row = 0;
	while (row < SQUARE_SIZE)
	{
		col = 0;
		while (col < SQUARE_SIZE)
		{
			draw_col = x_start + col;
			draw_row = y_start + row;
			put_pixel_to_image(&data->img, draw_col, draw_row, 0xFF0000);
			col++;
		}
		row++;
	}
	return (0);
}

int	draw_direction_line(t_data *data, int center_x, int center_y)
{
	int	line_length;
	int	i;
	int	lx;
	int	ly;

	line_length = 15;
	i = 0;
	while (i < line_length)
	{
		lx = center_x + (int)(data->player.dx * i);
		ly = center_y + (int)(data->player.dy * i);
		put_pixel_to_image(&data->img, lx, ly, 0x6495ED);
		i++;
	}
	return (0);
}

int	draw_player(t_data *data)
{
	int	center_x;
	int	center_y;
	int	x_start;
	int	y_start;

	center_x = (int)data->player.x;
	center_y = (int)data->player.y;
	x_start = center_x - (SQUARE_SIZE / 2);
	y_start = center_y - (SQUARE_SIZE / 2);
	draw_square(data, x_start, y_start);
	draw_direction_line(data, center_x, center_y);
	return (0);
}
