/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:23:30 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/20 22:55:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

extern char g_map[MAP_HEIGHT][MAP_WIDTH + 1];

int	player_init(t_data *data);
int	player_update(t_data *data, double delta_time);

#endif
