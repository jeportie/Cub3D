/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:01:22 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 21:22:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "game.h"

typedef struct s_map_api
{
	t_game_api	base;
	int			(*init)(t_map *self);
	int			(*parse)(t_map *self);
	int			(*render)(t_image *img);
	int			(*player)(t_game *game, t_image *img);
	int			(*destroy)(t_map *self);
	int			(*print)(void);
}						t_map_api;

extern const t_map_api		g_map_methods;

/* ~~~~~~~~~~~~~~~ The Map Class ~~~~~~~~~~~~~~~ */
typedef struct s_map
{
	t_game			base;

	const t_map_api	*methods;
}			t_map;

extern char					g_map[MAP_SIZE + 1];

t_map	*create_map(void);
int	init_map(t_map *map);
int	parse_map(t_map *map);
int	destroy_map(t_map *map);
int	print_map(void);

#endif
