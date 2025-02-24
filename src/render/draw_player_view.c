/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_view.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:08:08 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/23 21:18:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/compute.h"
#include "../../include/render.h"

int	draw_player_view(t_data *data, t_image *img)
{
	float		fov;
	float		start_angle;
	t_ray		ray;
	int			i;

	i = 0;
	fov = FOV_DEGREES * (M_PI / 180.0f);
	start_angle = normalize_angle(data->player.pose.angle - (fov / 2));
	draw_background(data, img);
	while (i < RAYS)
	{
		process_ray(data, &ray, start_angle, i, fov);
		draw_wall_slice(data, &ray, img);
		i++;
	}
	return (0);
}
