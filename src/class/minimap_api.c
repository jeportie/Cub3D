/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_api.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:59:56 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 17:13:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static int	minimap_methods_init(t_game_object *obj)
{
	t_minimap	*minimap;

	minimap = (t_minimap *)obj;
	return (init_minimap(minimap));
}

static int	minimap_methods_update(t_game_object *obj, double dt)
{
	(void)dt;
	(void)obj;
	return (0);
}

static int	minimap_methods_render(t_game_object *obj, t_game *game,
		int buffer_to_draw)
{
	return (render_minimap((t_minimap *)obj, game, buffer_to_draw));
}

static int	minimap_methods_destroy(t_game_object *obj)
{
	return (destroy_minimap((t_minimap *)obj));
}

static const t_methods	g_minimap_methods = {
	.init = minimap_methods_init,
	.update = minimap_methods_update,
	.render = minimap_methods_render,
	.destroy = minimap_methods_destroy
};

t_minimap	*create_minimap(void)
{
	t_minimap	*minimap;

	minimap = gc_malloc(sizeof(t_minimap));
	if (!minimap)
		return (NULL);
	ft_printf(DEB_MINIMAP_CREATE);
	minimap->object.methods = &g_minimap_methods;
	minimap->object.active = true;
	return (minimap);
}
