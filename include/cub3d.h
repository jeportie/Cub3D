/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:52:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 21:22:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>  // for close, etc.
# include <math.h>     // for cos, sin, etc. (may need -lm)
# include "define.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/include/libft.h"

typedef struct s_player
{
	double	x; // Player x-position (pixels)
	double	y; // Player y-position (pixels)
	double	angle; // Player viewing angle in radians
	double	dx; // cos(angle)
	double	dy; // sin(angle)
	bool	move_up;
	bool	move_down;
	bool	move_left;
	bool	move_right;
	bool	rot_left; // Pressing left arrow
	bool	rot_right; // Pressing right arrow
}			t_player;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp; // bits per pixel
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_player		player;
	struct timespec	last_time;
	double			delta_accumulator;
}				t_data;

int	game_loop(t_data *data);

#endif
