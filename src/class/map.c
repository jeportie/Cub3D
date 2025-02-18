/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:32:20 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 19:20:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "settings.h"
#include "../engine/graphic_engine.h"

/*
char	g_map[MAP_SIZE + 1] = {
	"11111001"
	"10000001"
	"10000001"
	"10011001"
	"10010001"
	"1000P001"
	"10000001"
	"11111111"
};*/

char	g_map[MAP_SIZE + 1] = {
	"1111111111111111"
	"1000000000000001"
	"1000000000000001"
	"1001100000010001"
	"1001000000010001"
	"1000P00000010001"
	"1000000000000001"
	"1000000000000001"
	"1000000001110001"
	"1000000000010001"
	"1000000000010001"
	"1000100000010001"
	"1000100000000001"
	"1000111100000001"
	"1000000000100001"
	"1000000000100001"
	"1111111111111111"
};

int	init_map(t_map *map)
{
	if (!map)
		return (1);
	ft_printf(DEB_MAP_INIT);
	ft_strlcpy(map->map, g_map, MAP_SIZE + 1);
	map->loaded = true;
	/* If you were reading from a .ber or .cub file, do that here. */
	return (0);
}

int	render_map(t_map *map, t_game *game, int buffer_to_draw)
{
	t_graphics		*engine;

	engine = game->graphic_engine;
	buffer_to_draw = (engine->current_img + 1) % 2;
//	ft_printf(DEB_MAP_RENDER);
	if (game->settings->toogle_map)
		draw_map(map, &engine->buffer[buffer_to_draw]);
	return 0;
}

int	print_map(t_map *map)
{
	int	row;
	int	col;

	ft_printf(DEB_MAP_PRINT);
	row = 0;
	while (row < MAP_HEIGHT)
	{
		col = 0;
		while (col < MAP_WIDTH)
		{
			ft_printf("%c ", map->map[row * MAP_WIDTH + col]);
			col++;
		}
		ft_printf("\n");
		row++;
	}
	ft_printf("\n");
	return (0);
}

int	destroy_map(t_map *map)
{
	if (!map)
		return (-1);
	ft_printf(DEB_MAP_DESTROY);
	return (0);
}
