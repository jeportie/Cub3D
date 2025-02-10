/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:52:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 14:08:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include "define.h"
# include "colors.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/include/libft.h"

/* ~~~~~~~~~~~~~~~ Forward Declarations ~~~~~~~~~~~~~~~ */
typedef struct	s_game	t_game;
typedef struct	s_settings	t_settings;
typedef struct	s_player	t_player;
typedef struct s_mlx_manager	t_mlx_manager;

/* ~~~~~~~~~~~~~~~ Public Prototypes ~~~~~~~~~~~~~~~ */

t_mlx_manager	*mlx_app_create(int width, int height, const char *title);
int				game_loop(t_game *game);

#endif
