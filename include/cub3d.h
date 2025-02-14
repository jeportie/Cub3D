/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:52:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/05 21:27:02 by jeportie         ###   ########.fr       */
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
# include "define.h"
# include "colors.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/include/libft.h"


typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
	double	dx;
	double	dy;
	double	plane_x;
	double	plane_y;
	bool	move_up;
	bool	move_down;
	bool	move_left;
	bool	move_right;
	bool	rot_left;
	bool	rot_right;
}			t_player;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_image			img[2];
	t_image			texture;
	int				current_img;
	t_player		player;
	struct timespec	last_time;
	double			delta_accumulator;
	bool			toogle_rays;
	bool			toogle_texture_mode;
	bool			toogle_map;
	bool			toogle_dda;
}				t_data;

typedef struct s_line_data
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_line_data;

extern char g_map[MAP_SIZE + 1];

int	game_loop(t_data *data);
int	print_map(void);

#endif
