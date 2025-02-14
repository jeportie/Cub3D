/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:33:11 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/14 18:29:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_GETTIME	"Error: clock_gettime() failed.\n"
# define ERR_MLX_INIT 	"Error: mlx_init() failed.\n"
# define ERR_MLX_WINDOW	"Error: mlx_new_window() failed.\n"
# define ERR_MLX_IMAGE	"Error: mlx_new_image() failed.\n"
# define ERR_MLX_DATA	"Error: mlx_get_data_addr() failed.\n"
# define ERR_TEX_INIT	"Error: Texture initialization failed.\n"
# define ERR_MLX_TEX	"Error: could not load texture from %s\n"

# define WARN_NOEQUAL	"Warning: texture size (%dx%d) != TILE_SIZE (%dx%d)\n"

# define ERR_MALLOC				"Mlx Error: malloc() failed\n"
# define ERR_NO_X_DISPLAY 		"Mlx Error: Could not open X Display\n"
# define ERR_WINDOW_CREATION 	"Mlx Error: Could not create new Window\n"
# define ERR_XPM_PARSE 			"Mlx Error: XPM parse failure\n"
# define ERR_XPM_ALLOC 			"Mlx Error: XPM memory allocation failed\n"

# define ERR_PRG_INIT_GAME		"Error: Failed to create Game.\n"
# define ERR_PRG_INIT_SETTINGS	"Error: Failed to create Settings.\n"
# define ERR_GAME_FULL_ARRAY	"Error: Object array is full!\n"

# define ERR_ORIGIN_INIT		"Error: Failed to allocate t_origin.\n"

#endif
