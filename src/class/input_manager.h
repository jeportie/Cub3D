/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:58:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 23:11:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_MANAGER_H
# define INPUT_MANAGER_H

# include "game.h"

typedef struct s_game_api	t_game_api;
typedef struct s_game	t_game;

typedef struct s_input_manager_api
{
	t_game_api	base;
}				t_input_manager_api;

extern const t_input_manager_api	g_input_manager_methods;

typedef struct s_input_manager
{
	t_game				base;

	const t_input_manager_api	*methods;
}				t_input_manager;

/* ~~~~~~~~~~~ CORE ENGINE METHODS ~~~~~~~~~~~~~*/
t_input_manager	*create_input_manager(void);
int				init_input_manager(t_input_manager *input_manager);
int				destroy_input_manager(t_input_manager *input_manager);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);

#endif
