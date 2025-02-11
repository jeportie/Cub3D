/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:32:20 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 20:32:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../engine/graphic_engine.h"
#include "raycaster.h"

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
	map->loaded = true;
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
