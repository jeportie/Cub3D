/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:03:29 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/17 13:54:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_H
# define CORE_ENGINE_H

# include "../class/game.h"

typedef struct s_core
{
	struct timespec	last_time;
	double			delta_accumulator;
	double			delta;
}				t_core;

t_core	*create_core_engine(void);
int		core_engine_init(t_core *time_state);
int		game_loop(void *params);
int		core_engine_shutdown(t_game *game);

double	get_time_in_seconds(struct timespec ts);

#endif
