/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:36:09 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 14:31:33 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define GAME_TITLE		"cub3d"

# define WINDOW_WIDTH	1420
# define WINDOW_HEIGHT	750

# define MINIMAP_SIZE   (MAP_WIDTH * MAP_SIZE)

# define THREE_D_X      620
# define THREE_D_WIDTH  900
# define THREE_D_HEIGHT 500

# define MAP_WIDTH		8
# define MAP_HEIGHT		8
# define MAP_SIZE		64
# define TILE_SIZE		32

# define SPEED			200.0
# define ROT_SPEED		3.0 

# define SQUARE_SIZE	5 

# define RAYS			900
# define EPSILON		0.0001f

# define FOV_DEGREES	60.0f
# define INNER_OFFSET	-0.0001f
# define MAX_STEPS 		64
# define MIN_DISTANCE 	10.0f

# define TEXTURE "assets/texture.xpm"
# define BPP 4

// LOGS
# define PRG

#endif
