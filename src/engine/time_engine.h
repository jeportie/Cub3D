/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:40:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 22:40:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_H
# define CORE_ENGINE_H

# include "../class/game.h"

int		core_engine_init(t_game *game);
int		core_engine_run(t_game *game);
int		core_engine_shutdown(t_game *game);

double	get_time_in_seconds(struct timespec ts);

#endif
