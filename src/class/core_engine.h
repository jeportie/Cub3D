/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:23:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 23:20:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_H
# define CORE_ENGINE_H

# include "game.h"

typedef struct s_game_api		t_game_api;
typedef struct s_game			t_game;

typedef struct s_core_engine_api
{
	t_game_api	base;
}				t_core_engine_api;

extern const t_core_engine_api	g_core_engine_methods;

typedef struct s_core_engine
{
	t_game					base;

	const t_core_engine_api	*methods;
}				t_core_engine;

/* ~~~~~~~~~~~ CORE ENGINE METHODS ~~~~~~~~~~~~~*/
t_core_engine	*create_core_engine(void);
int				init_core_engine(t_core_engine *core_engine);
int				run_core_engine(t_core_engine *core_engine);
int				destroy_core_engine(t_core_engine *core_engine);

double	get_time_in_seconds(struct timespec ts);

#endif
