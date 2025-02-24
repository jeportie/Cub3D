/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:52:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/23 21:42:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "define.h"
# include "colors.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/include/libft.h"

typedef struct s_coord
{
	float	x;
	float	y;
}				t_coord;

typedef struct s_scale
{
	float	x;
	float	y;
}				t_scale;

typedef struct s_transform
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	angle;
}				t_transform;

typedef struct s_player
{
	t_transform	pose;	
	bool		move_up;
	bool		move_down;
	bool		move_left;
	bool		move_right;
	bool		rot_left;
	bool		rot_right;
}			t_player;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_config
{
	char *map_filename;
	char *textures[4]; /* NO, SO, WE, EA*/
	int	textures_files_fd[4]; /* NO, SO, WE, EA*/
	int	map_file_fd;
	int floor_color;   /* RGB */
	int ceiling_color; /* RGB */
	int	metadata_count;
	int	flags[6];
}				t_config;

typedef struct s_map
{
	char	**layout;   // 2D array for the map
	int		begin_map_index; // Index of the beginning of the map;
	int		end_map_index; // Index of the end of the map;
	int		width;       // Map width
	int		height;      // MAp height
	int		player_i;    // player coordinate
	int		player_j;    // player coordinate
	char	player_dir; // player starting orientation
}				t_map;

typedef struct	s_parse
{
	t_config	config;
	t_map		map;
}				t_parse;

typedef struct s_data
{
	t_parse			parse;
	char			*map;
	void			*mlx;
	void			*win;
	t_image			img[2];
	t_image			walls[4];
	int				current_img;
	t_player		player;
	struct timespec	last_time;
	float			delta_accumulator;
	bool			toogle_texture_mode;
}				t_data;

int	game_loop(t_data *data);

#endif
