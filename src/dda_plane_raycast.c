/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_plane_raycast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:09:36 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/30 15:16:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

int	compute_initial_sides_plane(t_dda *d)
{
	if (d->dir_x < 0)
	{
		d->step_x = -1;
		d->side_x = (d->px - d->map_x) * d->delta_x;
	}
	else
	{
		d->step_x = 1;
		d->side_x = (d->map_x + 1.0f - d->px) * d->delta_x;
	}
	if (d->dir_y < 0)
	{
		d->step_y = -1;
		d->side_y = (d->py - d->map_y) * d->delta_y;
	}
	else
	{
		d->step_y = 1;
		d->side_y = (d->map_y + 1.0f - d->py) * d->delta_y;
	}
	return (0);
}

t_rayinfo	cast_ray_dda_plane(t_data *data, double ray_dir_x, double ray_dir_y)
{
	t_rayinfo	rayinfo;
	t_dda		d;
	double		pos_x;
	double		pos_y;
	int			hit;
	float		perp_wall_dist;

	pos_x = data->player.x;
	pos_y = data->player.y;
	d.px = (float)pos_x;
	d.py = (float)pos_y;
	d.dir_x = (float)ray_dir_x;
	d.dir_y = (float)ray_dir_y;
	d.map_x = (int)pos_x;
	d.map_y = (int)pos_y;
	if (d.dir_x == 0.0f)
		d.delta_x = 1e30f;
	else
		d.delta_x = fabsf(1.0f / d.dir_x);
	if (d.dir_y == 0.0f)
		d.delta_y = 1e30f;
	else
		d.delta_y = fabsf(1.0f / d.dir_y);
	compute_initial_sides_plane(&d);
	hit = 0;
	while (!hit)
	{
		if (d.side_x < d.side_y)
		{
			d.side_x += d.delta_x;
			d.map_x += d.step_x;
			d.side = 0;
		}
		else
		{
			d.side_y += d.delta_y;
			d.map_y += d.step_y;
			d.side = 1;
		}
		if (d.map_x < 0 || d.map_y < 0 || d.map_x >= MAP_WIDTH || d.map_y >= MAP_HEIGHT)
			break ;
		if (g_map[d.map_y * MAP_WIDTH + d.map_x] == '1')
			hit = 1;
	}
	if (d.side == 0)
		perp_wall_dist = d.side_x - d.delta_x;
	else
		perp_wall_dist = d.side_y - d.delta_y;
	rayinfo.dist = perp_wall_dist;
	rayinfo.rx = d.px + d.dir_x * perp_wall_dist;
	rayinfo.ry = d.py + d.dir_y * perp_wall_dist;
	rayinfo.tile_x = d.map_x;
	rayinfo.tile_y = d.map_y;
	rayinfo.map_index = d.side;
	return (rayinfo);
}
