/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:52:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 15:10:45 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include "define.h"
# include "colors.h"
# include "error.h"
# include "debug.h"
# include "coordinates.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/include/libft.h"
# include "../lib/libgc/include/libgc.h"

/* ~~~~~~~~~~~~~~~ Forward Declarations ~~~~~~~~~~~~~~~ */
typedef struct s_origin				t_origin;
typedef struct s_origin_api			t_origin_api;
typedef struct s_game				t_game;
typedef struct s_game_api			t_game_api;
typedef struct s_game_object		t_game_object;
typedef struct s_settings			t_settings;
typedef struct s_settings_api		t_settings_api;
typedef struct s_callback			t_callback;
typedef struct s_listener			t_listener;
typedef struct s_listener_api		t_listener_api;
typedef struct s_core				t_core;
typedef struct s_player				t_player;
typedef struct s_player_api			t_player_api;
typedef struct s_map				t_map;
typedef struct s_map_api			t_map_api;
typedef struct s_minimap			t_minimap;
typedef struct s_minimap_api		t_minimap_api;
typedef struct s_graphic_engine		t_graphic_engine;
typedef struct s_graphic_engine_api	t_graphic_engine_api;
typedef struct s_mlx_manager		t_mlx_manager;
typedef struct s_image				t_image;
typedef struct s_graphics			t_graphics;
typedef struct s_ray				t_ray;	

typedef struct s_coord				t_coord;
typedef struct s_transform			t_transform;

#endif
