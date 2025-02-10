/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_api.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:53:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 21:52:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "graphic_engine.h"
#include "raycaster.h"

const t_map_api	g_map_methods = {
	.init = init_map,
	.parse = parse_map,
	.render = draw_map,
	.player = draw_player,
//	.ray = draw_rays,
//	.vector = draw_direction_line,
	.print = print_map,
	.destroy = destroy_map
};

t_map	*create_map(void)
{
	t_map	*map;

	map = gc_malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	ft_printf("[Map Debug] create_map() called\n");
	map->methods = &g_map_methods;
	return (map);
}

int	init_map(t_map *map)
{
	if (!map)
		return (1);
	ft_printf("[Map Debug] init_map() called\n");
	return (0);
}

int	parse_map(t_map *map)
{
	if (!map)
		return (1);
	ft_printf("[Map Debug] parse_map() called\n");
	/* If you were reading from a .ber or .cub file, do that here. */
	return (0);
}

int	destroy_map(t_map *map)
{
	if (!map)
		return (-1);
	ft_printf("[Map Debug] destroy_map() called\n");
	return (0);
}
