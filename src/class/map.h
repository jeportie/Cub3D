/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:01:22 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 18:28:33 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "game.h"
# include "game_object.h"

typedef struct s_map
{
	t_game_object	object;
	bool			loaded;

}			t_map;

extern char	g_map[MAP_SIZE + 1];

t_map	*create_map(void);
int		init_map(t_map *map);
int		parse_map(t_map *map);
int		destroy_map(t_map *map);
int		print_map(void);

#endif
