/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_system.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:13:55 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/14 22:22:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "callback_system.h"
#include "../class/game.h"
#include "../class/player.h"

int	key_press(int keycode, void *param)
{
	int			i;
	t_listener	*l;
	t_game		*game;

	game = (t_game *)param;
	ft_printf(DEB_CALLB_PRESS, keycode);
	i = 0;
	while (i < game->input_manager->count)
	{
		l = &game->input_manager->listeners[i];
		if (l->methods->on_key_press)
			l->methods->on_key_press(l->instance, keycode);
		i++;
	}
	return (0);
}

int	key_release(int keycode, void *param)
{
	int			i;
	t_listener	*l;
	t_game		*game;

	game = (t_game *)param;
	ft_printf(DEB_CALLB_RELEASE, keycode);
	i = 0;
	while (i < game->input_manager->count)
	{
		l = &game->input_manager->listeners[i];
		if (l->methods->on_key_release)
			l->methods->on_key_release(l->instance, keycode);
		i++;
	}
	return (0);
}

int	add_listener(t_callback *mgr, void *instance, const t_listener_api *methods)
{
	if (mgr->count >= MAX_LISTENERS)
		return (1);
	mgr->listeners[mgr->count].instance = instance;
	mgr->listeners[mgr->count].methods = methods;
	mgr->count++;
	return (0);
}

int	input_manager_init(t_game *game, t_callback *input_manager)
{
	input_manager->count = 0;
	add_listener(input_manager, game, &g_game_listener_api);
	add_listener(input_manager, game->player, &g_player_listener_api);
	ft_printf(DEB_CALLB_INIT);
	return (0);
}

t_callback	*create_input_manager(void)
{
	t_callback	*input_manager;

	ft_printf(DEB_CALLB_CREATE);
	input_manager = gc_malloc(sizeof(t_callback));
	if (!input_manager)
		return (NULL);
	return (input_manager);
}
