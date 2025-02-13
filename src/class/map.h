/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:01:22 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 22:45:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "game.h"
# include "game_object.h"

typedef struct s_map
{
	t_game_object	object;
	char			map[MAP_SIZE + 1];
	bool			loaded;

}			t_map;

extern char	g_map[MAP_SIZE + 1];

t_map	*create_map(void);

int		init_map(t_map *map);
int		render_map(t_game *game);
int		print_map(t_map *map);
int		destroy_map(t_map *map);

#endif
