/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:36:09 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/23 00:11:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define GAME_TITLE		"cub3d"

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1000

# define MINIMAP_SIZE   512     // 8 tiles * 64 pixels

# define THREE_D_X      0
# define THREE_D_WIDTH  1920 // 1600 - 512 = 1088
# define THREE_D_HEIGHT 1000

# define MAP_WIDTH		8
# define MAP_HEIGHT		8
# define MAP_SIZE		64
# define TILE_SIZE		32

# define SPEED			100.0  // Movement speed in pixels per second
# define ROT_SPEED		3.0   // Radians per second 

# define SQUARE_SIZE	5 

# define RAYS			1920
# define EPSILON		0.0001f

# define FOV_DEGREES	60.0f
# define INNER_OFFSET	-0.001f
# define MAX_STEPS 		64
# define MIN_DISTANCE 10.0f // Adjust based on gameplay needs

#endif
