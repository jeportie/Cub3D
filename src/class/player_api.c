/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_api.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:23:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 14:08:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/input.h"
#include "player.h"
#include "../engine/callback_system.h"

static int	player_methods_init(t_game_object *obj)
{
	return init_player((t_player*)obj);
}

static int	player_methods_update(t_game_object *obj, double dt)
{
	return update_player((t_player*)obj, dt);
}

static int	player_methods_render(t_game_object *obj, t_game *game, int buffer_to_draw)
{
	return render_player((t_player *)obj, game, buffer_to_draw);
}

static int player_methods_destroy(t_game_object *obj)
{
	return destroy_player((t_player*)obj);
}

const t_methods	g_player_methods = {
	.init = player_methods_init,
	.update = player_methods_update,
	.render = player_methods_render,
	.destroy = player_methods_destroy
};

t_player	*create_player(void)
{
	t_player	*player;

	player = gc_malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	ft_printf(DEB_PLAYER_CREATE);
	player->object.methods = &g_player_methods;
	player->object.active  = true;

	player->move_up = false;
	player->move_down = false;
	player->move_left = false;
	player->move_right = false;
	player->rot_left = false;
	player->rot_right = false;
	return (player);
}

static int	player_on_key_press(void *self, int keycode)
{
	t_player	*player;

	player = (t_player *)self;
	if (keycode == KEY_LEFT_ARROW)
		player->rot_left = true;
	else if (keycode == KEY_RIGHT_ARROW)
		player->rot_right = true;
	else if (keycode == KEY_W || keycode == KEY_UP_ARROW)
		player->move_up = true;
	else if (keycode == KEY_S || keycode == KEY_DOWN_ARROW)
		player->move_down = true;
	else if (keycode == KEY_A)
		player->move_left = true;
	else if (keycode == KEY_D)
		player->move_right = true;
	return (0);
}

static int player_on_key_release(void *self, int keycode)
{
	t_player	*player;

	player = (t_player *)self;
	if (keycode == KEY_LEFT_ARROW)
		player->rot_left = false;
	else if (keycode == KEY_RIGHT_ARROW)
		player->rot_right = false;
	else if (keycode == KEY_W || keycode == KEY_UP_ARROW)
		player->move_up = false;
	else if (keycode == KEY_S || keycode == KEY_DOWN_ARROW)
		player->move_down = false;
	else if (keycode == KEY_A)
		player->move_left = false;
	else if (keycode == KEY_D)
		player->move_right = false;
	return (0);
}

const t_listener_api	g_player_listener_api = {
    .on_key_press   = player_on_key_press,
    .on_key_release = player_on_key_release
};
