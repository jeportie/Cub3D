/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_api.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:53:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 20:32:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../engine/graphic_engine.h"
#include "raycaster.h"


static int	map_methods_init(t_game_object *obj)
{
	t_map *map = (t_map*)obj;
	return init_map(map);
}

static int	map_methods_update(t_game_object *obj, double dt)
{
	(void)dt;
	/* e.g. animate something, or do nothing */
	return 0;
}

int	map_render(t_map *map, t_image *img)
{
	ft_printf("[Map Debug] map_render() called\n");
	draw_map(img); /* your existing function that draws the tiles */
	return 0;
}

static int	map_methods_render(t_game_object *obj, t_image *img)
{
	t_map *map = (t_map*)obj;
	return map_render(map, img);
}

static int	map_methods_destroy(t_game_object *obj)
{
	return destroy_map((t_map*)obj);
}

static const t_methods	g_map_methods = {
	.init = map_methods_init,
	.update = map_methods_update,
	.render = map_methods_render,
	.destroy = map_methods_destroy
};

t_map	*create_map(void)
{
	t_map	*map;

	map = gc_malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	ft_printf("[Map Debug] create_map() called\n");
	map->object.methods = &g_map_methods;
	map->object.active = true;
	map->loaded = false;
	return (map);
}
