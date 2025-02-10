/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:16:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 21:23:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "origin.h"

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
	t_mlx_manager		*app;
	t_graphics			*graphics;
	t_player			*player;
	t_map				*map;

	const t_game_api	*methods;
}				t_game;

/* ~~~~~~~~~~~ GAME METHODS ~~~~~~~~~~~~~*/
t_game		*create_game(void);
int			init_game(t_game *game);
int			run_game(t_game *game);
int			destroy_game(t_game *game);

#endif
