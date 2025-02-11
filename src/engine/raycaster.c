/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:15:21 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 18:15:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "../../include/compute.h"

const t_raycaster_api	g_raycaster_methods = {
	.init = init_raycaster,
	.destroy = destroy_raycaster
};

// DDA RAYCAST
void	init_dda_struct(t_dda *d, t_data *data, float angle)
{
	d->px = data->player.x;
	d->py = data->player.y;
	d->dir_x = cosf(angle);
	d->dir_y = sinf(angle);
	d->map_x = (int)(d->px / TILE_SIZE);
	d->map_y = (int)(d->py / TILE_SIZE);
	d->step_x = 1;
	if (d->dir_x < 0.0f)
		d->step_x = -1;
	d->step_y = 1;
	if (d->dir_y < 0.0f)
		d->step_y = -1;
	if (fabsf(d->dir_x) < EPSILON)
		d->dir_x = EPSILON;
	if (fabsf(d->dir_y) < EPSILON)
		d->dir_y = EPSILON;
	d->delta_x = fabsf(1.0f / d->dir_x) * TILE_SIZE;
	d->delta_y = fabsf(1.0f / d->dir_y) * TILE_SIZE;
	d->side_x = 0.0f;
	d->side_y = 0.0f;
	d->side = 0;
	d->dist = 0.0f;
}

int	run_dda_loop(t_dda *d)
{
	int	out_of_bounds;

	out_of_bounds = 0;
	while (1)
	{
		if (d->side_x < d->side_y)
		{
			d->side_x += d->delta_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_y += d->delta_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->map_x < 0 || d->map_x >= MAP_WIDTH
			|| d->map_y < 0 || d->map_y >= MAP_HEIGHT)
		{
			out_of_bounds = 1;
			break ;
		}
		if (g_map[d->map_y * MAP_WIDTH + d->map_x] == '1')
			break ;
	}
	return (out_of_bounds);
}

void	fill_rayinfo(t_dda *d, t_data *data, t_rayinfo *ray)
{
	float	dist;

	if (d->side == 0)
		dist = d->side_x - d->delta_x;
	else
		dist = d->side_y - d->delta_y;
	ray->dist = dist;
	ray->rx = d->px + (dist * d->dir_x);
	ray->ry = d->py + (dist * d->dir_y);
	ray->tile_x = d->map_x;
	ray->tile_y = d->map_y;
	ray->map_index = d->side;
	(void)data;
}

t_rayinfo	cast_ray_dda(t_data *data, float angle)
{
	t_rayinfo	ray;
	t_dda		d;

	ft_bzero(&ray, sizeof(t_rayinfo));
	ft_bzero(&d, sizeof(t_dda));
	init_dda_struct(&d, data, angle);
	compute_initial_sides(&d, data);
	run_dda_loop(&d);
	fill_rayinfo(&d, data, &ray);
	return (ray);
}

//DUAL PASS
t_rayinfo	cast_vertical_ray(t_data *data, float ray_angle)
{
	t_ray_cast	ray;

	ray.player_x = data->player.x;
	ray.player_y = data->player.y;
	ray.cos_a = get_safe_cos(ray_angle);
	ray.sin_a = get_safe_sin(ray_angle);
	ray.flag = (ray.cos_a < 0);
	ray.tan_a = calculate_tan_a(ray_angle);
	ray.intercept_x = calculate_intercept(ray.player_x, ray.flag);
	ray.intercept_y = ray.player_y + (ray.intercept_x - ray.player_x) * ray.tan_a;
	ray.step_x = calculate_step_primary(ray.flag, TILE_SIZE);
	ray.step_y = calculate_step_secondary(ray.step_x, ray.tan_a);
	while (true)
	{
		ray.result.tile_x = (int)(ray.intercept_x / TILE_SIZE);
		ray.result.tile_y = (int)(ray.intercept_y / TILE_SIZE);
		if (ray.result.tile_x < 0 || ray.result.tile_x >= MAP_WIDTH
			|| ray.result.tile_y < 0 || ray.result.tile_y >= MAP_HEIGHT
			|| g_map[ray.result.tile_y * MAP_WIDTH + ray.result.tile_x] == '1')
			break ;
		ray.intercept_x += ray.step_x;
		ray.intercept_y += ray.step_y;
	}
	ray.result.rx = ray.intercept_x;
	ray.result.ry = ray.intercept_y;
	ray.result.dist = calculate_distance(ray.result.rx - ray.player_x,
			ray.result.ry - ray.player_y);
	return (ray.result);
}

t_rayinfo	cast_horizontal_ray(t_data *data, float ray_angle)
{
	t_ray_cast	ray;

	ray.player_x = data->player.x;
	ray.player_y = data->player.y;
	ray.sin_a = get_safe_sin(ray_angle);
	ray.cos_a = get_safe_cos(ray_angle);
	ray.flag = (ray.sin_a < 0);
	ray.tan_a = ray.cos_a / ray.sin_a;
	ray.intercept_y = calculate_intercept(ray.player_y, ray.flag);
	ray.intercept_x = ray.player_x + (ray.intercept_y - ray.player_y) * ray.tan_a;
	ray.step_y = calculate_step_primary(ray.flag, TILE_SIZE);
	ray.step_x = calculate_step_secondary(ray.step_y, ray.tan_a);
	while (true)
	{
		ray.result.tile_x = (int)(ray.intercept_x / TILE_SIZE);
		ray.result.tile_y = (int)(ray.intercept_y / TILE_SIZE);
		if (ray.result.tile_x < 0 || ray.result.tile_x >= MAP_WIDTH
			|| ray.result.tile_y < 0 || ray.result.tile_y >= MAP_HEIGHT
			|| g_map[ray.result.tile_y * MAP_WIDTH + ray.result.tile_x] == '1')
			break ;
		ray.intercept_x += ray.step_x;
		ray.intercept_y += ray.step_y;
	}
	ray.result.rx = ray.intercept_x;
	ray.result.ry = ray.intercept_y;
	ray.result.dist = calculate_distance(ray.result.rx - ray.player_x,
			ray.result.ry - ray.player_y);
	return (ray.result);
}
