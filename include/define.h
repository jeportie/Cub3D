/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:36:09 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 19:19:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define GAME_TITLE		"cub3d"

# define WINDOW_WIDTH	1500
# define WINDOW_HEIGHT	900

# define MINIMAP_SIZE   (MAP_WIDTH * MAP_SIZE)

# define THREE_D_X      600
# define THREE_D_WIDTH  900
# define THREE_D_HEIGHT 540

# define MAP_WIDTH		16//8
# define MAP_HEIGHT		16//8
# define MAP_SIZE		1024//64

#define MINIMAP_SCALE   12

# define TILE_SIZE		64

# define SPEED			300.0
# define ROT_SPEED		3.0 

# define SQUARE_SIZE	5 

# define RAYS			(THREE_D_WIDTH)
# define EPSILON		0.0001f

# define FOV_DEGREES	60.0f
# define INNER_OFFSET	-0.0001f
# define MAX_STEPS 		64
# define MIN_DISTANCE 	10.0f

# define MAX_DEBUG_LINES 1
# define MAX_LINE_LENGTH 128

# define BPP 4

// LOGS
# define PRG

#endif
