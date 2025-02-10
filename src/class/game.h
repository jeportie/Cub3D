/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:16:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 14:11:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "origin.h"

typedef struct s_mlx_manager	t_mlx_manager;
typedef struct s_player			t_player;

typedef struct s_game_api
{
	t_origin_api	base;
	int				(*init)(struct s_game *self);
	int				(*run)(struct s_game *self);
	int				(*destroy)(struct s_game *self);
}				t_game_api;

extern const t_game_api	g_game_methods;

typedef struct s_game
{
	t_origin			base;
	t_settings			*settings;
	t_mlx_manager		*app;
//	t_graphics			graphics;
//	t_player			player;

	const t_game_api	*methods;
}				t_game;

/* ~~~~~~~~~~~ GAME METHODS ~~~~~~~~~~~~~*/
t_game		*create_game(void);
int			init_game(t_game *game);
int			run_game(t_game *game);
int			destroy_game(t_game *game);

#endif
