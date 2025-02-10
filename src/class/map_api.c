/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_api.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:53:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 18:01:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

const t_map_api	g_map_methods = {
	.init = init_map,
	.parse = parse_map,
//	.render = draw_map,
//	.player = draw_player,
//	.ray = draw_rays,
//	.vector = draw_direction_line,
	.print = print_map,
	.destroy = destroy_map
};

t_map	*create_map(t_game *game);

int	init_map(t_map *map);

int	parse_map(t_map *map);

int	destroy_map(t_map *map);
