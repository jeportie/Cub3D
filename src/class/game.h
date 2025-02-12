/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:16:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/12 09:03:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "origin.h"
# include "game_object.h"

# define MAX_OBJECTS  32

typedef struct s_game_api
{
	t_origin_api	base;
	int				(*init)(t_game *self);
	int				(*run)(t_game *self);
	t_player		*(*new_player)(void);
	t_map			*(*new_map)(void);
	int				(*destroy)(t_game *self);
}				t_game_api;

extern const t_game_api			g_game_methods;

typedef struct s_game
{
	t_origin			base;
	t_settings			*settings;
	t_graphics			*graphic_engine;
	t_player			*player;
	t_map				*map;

	t_game_object		*objects[MAX_OBJECTS];
	int					object_count;

	const t_game_api	*methods;
}				t_game;

/* ~~~~~~~~~~~ GAME METHODS ~~~~~~~~~~~~~*/
t_game		*create_game(void);
int			init_game(t_game *game);
int			run_game(t_game *game);
int			destroy_game(t_game *game);

#endif
