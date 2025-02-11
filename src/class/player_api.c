/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_api.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:23:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 20:37:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static int	player_methods_init(t_game_object *obj)
{
	return init_player((t_player*)obj);
}

static int	player_methods_update(t_game_object *obj, double dt)
{
	return player_update((t_player*)obj, dt);
}

static int	player_methods_render(t_game_object *obj, t_image *img)
{
	return player_render((t_player*)obj, img);
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
	ft_printf("[Player Debug] create_player() called\n");
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
