/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:26:06 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 23:12:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "game.h"

typedef struct s_game_api		t_game_api;
typedef struct s_game			t_game;

typedef struct s_player_api
{
	t_game_api	base;
	int			(*init)(struct s_player *self);
	int			(*parse)(struct s_player *self);
	int			(*destroy)(struct s_player *self);
	int			(*print)(void);
}						t_player_api;

extern const t_player_api		g_player_methods;

/* ~~~~~~~~~~~~~~~ Player Class ~~~~~~~~~~~~~~~ */
typedef struct s_player
{
	double				x;
	double				y;
	double				angle;
	double				dx;
	double				dy;
	double				plane_x;
	double				plane_y;
	bool				move_up;
	bool				move_down;
	bool				move_left;
	bool				move_right;
	bool				rot_left;
	bool				rot_right;
	const t_player_api	*methods;
}			t_player;

int	player_init(t_game *game);
int	player_update(t_game *game, double delta_time);

#endif
