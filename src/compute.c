/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:26:28 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 16:32:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/compute.h"

float	normalize_angle(float angle)
{
	float	two_pi;

	two_pi = 2.0f * M_PI;
	angle = fmodf(angle, two_pi);
	if (angle < 0)
		angle += two_pi;
	return (angle);
}

float	correct_fisheye(float player_angle, float ray_angle, float distance)
{
	float	angle_difference;

	angle_difference = player_angle - ray_angle;
	angle_difference = fmodf(angle_difference + M_PI, 2.0f * M_PI) - M_PI;
	return (distance * cosf(angle_difference));
}

int	calculate_wall_height(float distance, float fov)
{
	float	height;

	if (distance < 0.0001f)
		distance = 0.0001f;
	height = (TILE_SIZE / distance) * (THREE_D_WIDTH / 2) / tanf(fov / 2);
	if (height > THREE_D_HEIGHT)
		height = THREE_D_HEIGHT;
	return ((int)height);
}

float	get_safe_cos(float angle)
{
	float	cos_a;

	cos_a = cosf(angle);
	if (fabsf(cos_a) < EPSILON)
	{
		if (cos_a > 0)
			return (EPSILON);
		else
			return (-EPSILON);
	}
	return (cos_a);
}

float	get_safe_sin(float angle)
{
	float	sin_a;

	sin_a = sinf(angle);
	if (fabsf(sin_a) < EPSILON)
	{
		if (sin_a > 0)
			return (EPSILON);
		else
			return (-EPSILON);
	}
	return (sin_a);
}

float	calculate_intercept(float player_pos, int flag, char mode)
{
	if (!flag)
	{
		if (mode == 'v')
			return (floorf(player_pos / TILE_SIZE)
				* TILE_SIZE + TILE_SIZE - INNER_OFFSET);
		else
			return (floorf(player_pos / TILE_SIZE)
				* TILE_SIZE + TILE_SIZE - INNER_OFFSET);
	}
	else
	{
		if (mode == 'v')
			return (floorf(player_pos / TILE_SIZE) * TILE_SIZE + INNER_OFFSET);
		else
			return (floorf(player_pos / TILE_SIZE) * TILE_SIZE + INNER_OFFSET);
	}
}

float	calculate_tan_a(float sin_a, float cos_a)
{
	return (sin_a / cos_a);
}

float	calculate_step_primary(int flag, float tile_size)
{
	if (flag)
		return (-tile_size);
	else
		return (tile_size);
}

float	calculate_step_secondary(float step_primary, float tan_a)
{
	return (step_primary * tan_a);
}

float	calculate_distance(float delta_x, float delta_y)
{
	return (sqrtf(delta_x * delta_x + delta_y * delta_y));
}
