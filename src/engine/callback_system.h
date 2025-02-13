/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_system.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:58:25 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 00:04:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLBACK_SYSTEM_H
# define CALLBACK_SYSTEM_H

# define MAX_LISTENERS 10
# include "../class/game.h"

typedef struct s_listener_api
{
	int	(*on_key_press)(void *self, int keycode);
	int	(*on_key_release)(void *self, int keycode);
}				t_listener_api;

typedef struct s_listener
{
	const t_listener_api	*methods;
	void					*instance;
}	t_listener;

typedef struct s_callback
{
	t_listener	listeners[MAX_LISTENERS];
	int			count;
}				t_callback;

t_callback	*create_input_manager(void);
int			input_manager_init(t_game *game, t_callback *input_manager);
int			input_manager_shutdown(t_game *game);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);

int			add_listener(t_callback *mgr, void *instance, const t_listener_api *methods);

#endif
