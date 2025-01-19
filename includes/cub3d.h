/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:37:30 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/17 21:39:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/include/libft.h"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define SQUARE_SIZE   10
#define SPEED         200.0

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				square_x;
	int				square_y;
	bool			key_w;
	bool			key_s;
	bool			key_a;
	bool			key_d;
	struct timespec	last_time;
	double			delta_accumulator;
}					t_data;
