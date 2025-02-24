/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:18:15 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 12:09:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/engine.h"
#include "../../include/error.h"

int	fps_update(t_data *data, double *delta, double *time_step)
{
	struct timespec	time;

	if (clock_gettime(CLOCK_MONOTONIC, &time) != 0)
	{
		ft_dprintf(2, ERR_GETTIME);
		return (1);
	}
	*delta = get_time_in_seconds(time) - get_time_in_seconds(data->last_time);
	data->last_time = time;
	if (*delta > 0.1)
		*delta = 0.1;
	data->delta_accumulator += *delta;
	*time_step = 1.0 / FRAME_RATE;
	return (0);
}
