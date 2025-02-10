/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:26:06 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 21:27:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "game.h"

typedef struct s_player_api
{
	t_game_api	base;
	int			(*init)(t_player *self);
	int			(*view)(t_game *game, t_image *img);
	int			(*move)(t_player *player, double delta_time);
	int			(*destroy)(t_player *self);
}						t_player_api;

extern const t_player_api		g_player_methods;

/* ~~~~~~~~~~~~~~~ Player Class ~~~~~~~~~~~~~~~ */
typedef struct s_player
{
	t_game				base;
	double				x;
	double				y;
	double				angle;
	double				dx;
	double				dy;
	bool				move_up;
	bool				move_down;
	bool				move_left;
	bool				move_right;
	bool				rot_left;
	bool				rot_right;
	const t_player_api	*methods;
}			t_player;

t_player	*create_player(void);
int			init_player(t_player *player);
int			player_update(t_player *player, double delta_time);
int			destroy_player(t_player *player);

#endif
