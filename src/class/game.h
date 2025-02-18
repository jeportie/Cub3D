/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:16:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 15:13:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "origin.h"
# include "game_object.h"

# define MAX_OBJECTS  32

typedef struct s_debug_log
{
	char	lines[MAX_DEBUG_LINES][MAX_LINE_LENGTH];
	int		write_index;
	int		total_lines;
}				t_debug_log;

typedef struct s_game_api
{
	t_origin_api	base;
	int				(*init)(t_game *self);
	int				(*run)(t_game *self);
	t_callback		*(*new_input)(void);
	t_core			*(*new_core)(void);
	t_graphics		*(*new_graphics)(void);
	t_player		*(*new_player)(void);
	t_map			*(*new_map)(void);
	t_minimap		*(*new_minimap)(void);
	int				(*destroy)(t_game *self);
}				t_game_api;

extern const t_game_api			g_game_methods;
extern const t_listener_api		g_game_listener_api;

typedef struct s_game
{
	t_origin			base;
	t_settings			*settings;
	t_debug_log			debug_log;

	t_core				*time_state;
	t_graphics			*graphic_engine;
	t_callback			*input_manager;

	t_player			*player;
	t_map				*map;
	t_minimap			*minimap;

	t_game_object		*objects[MAX_OBJECTS];
	int					object_count;

	const t_game_api	*methods;
}				t_game;

/* ~~~~~~~~~~~ GAME METHODS ~~~~~~~~~~~~~*/
t_game		*create_game(void);
int			init_game(t_game *game);
int			run_game(t_game *game);
int			destroy_game(t_game *game);

int			debug_log_add(t_debug_log *log, const char *fmt, ...);
int			init_debug_log(t_game *game);
int			draw_debug_log(void *mlx_ptr, void *win_ptr, t_debug_log *log);

#endif
