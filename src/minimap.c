/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:53:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/22 11:52:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minimap.h"
#include "../include/engine.h"
#include "../include/colors.h"

char	g_map[MAP_SIZE + 1] = {
	"11111111"
	"10010001"
	"10010001"
	"10010011"
	"10001001"
	"10000001"
	"1P000101"
	"11111111"
};

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
			x = col * TILE_SIZE + px;
			y = row * TILE_SIZE + py;
			color = base_color;
			if (py == 0 || py == TILE_SIZE - 1
				|| px == 0 || px == TILE_SIZE - 1)
				color = GREY;
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
				base_color = WHITE;
			else
				base_color = BLACK;
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
			put_pixel_to_image(&data->img, draw_col, draw_row, RED);
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
		put_pixel_to_image(&data->img, lx, ly, PURPLE);
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
