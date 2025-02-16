/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:26:06 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 14:07:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "game.h"
# include "game_object.h"

/* ~~~~~~~~~~~~~~~ Player Class ~~~~~~~~~~~~~~~ */
typedef struct s_player
{
	t_game_object		object;
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
}			t_player;

extern const t_listener_api	g_player_listener_api;

t_player	*create_player(void);
int			init_player(t_player *player);
int			update_player(t_player *player, double delta_time);
int			render_player(t_player *player, t_game *game, int  buffer_to_draw);
int			destroy_player(t_player *player);

#endif
