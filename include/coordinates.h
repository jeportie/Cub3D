/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:41:28 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 10:24:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES_H
# define COORDINATES_H

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_transform
{
	double	x;
	double	y;
	double	angle;
	double	dx;
	double	dy;
}				t_transform;

typedef struct s_partial_tile
{
	t_coord	dist;
	t_coord	global;
	t_coord	start;
	t_coord	center;
}				t_partial_tile;

typedef struct s_minimap_coords
{
	t_coord	player;
	t_coord	center;
	t_coord	range;
	t_coord	index;
	t_coord	tile_center;
	t_coord	frac;
	t_coord	real_center;
	t_coord	tile;
	t_coord	screen;
	t_coord	tl; //top_left
	t_coord	tr; //top_right
	t_coord	bl; //botom_left
	t_coord	br; //botom_right
	float	radius;
	float	dist_tl;
	float	dist_tr;
	float	dist_bl;
	float	dist_br;
}			t_minimap_coords;

#endif
