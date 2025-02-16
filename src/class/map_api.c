/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_api.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:53:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 13:24:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	map_methods_init(t_game_object *obj)
{
	t_map	*map;

	map = (t_map *)obj;
	return (init_map(map));
}

static int	map_methods_print(t_game_object *obj)
{
	t_map	*map;

	map = (t_map *)obj;
	return (print_map(map));
}


static int	map_methods_update(t_game_object *obj, double dt)
{
	(void)dt;
	(void)obj;
	/* e.g. to use when the minimap will be dynamic*/
	return (0);
}

static int	map_methods_render(t_game_object *obj, t_game *game)
{
	return (render_map((t_map *)obj, game));
}

static int	map_methods_destroy(t_game_object *obj)
{
	return (destroy_map((t_map *)obj));
}

static const t_methods	g_map_methods = {
	.init = map_methods_init,
	.print = map_methods_print, 
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
	ft_printf(DEB_MAP_CREATE);
	map->object.methods = &g_map_methods;
	map->object.active = true;
	map->loaded = false;
	return (map);
}
