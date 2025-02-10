/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:21:26 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 23:20:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_MANAGER_H
# define TEXTURE_MANAGER_H

# include "graphic_engine.h"

typedef struct s_game_api	t_game_api;
typedef struct s_game	t_game;

typedef struct s_texure_manager_api
{
	t_game_api	base;
}				t_texure_manager_api;

extern const t_texure_manager_api	g_texure_manager_methods;
int				run_texure_manager(t_texure_manager *texure_manager);

typedef struct s_texure_manager
{
	t_game			base;

	const t_texure_manager_api	*methods;
}				t_texure_manager;

typedef struct s_tex
{
	float	full_height;
	float	ty_step;
	float	ty_off;
	float	ty;
	int		y;
	int		tx;
	int		tex_y;
	int		color;
	int		clamped_height;
}	t_tex;

/* ~~~~~~~~~~~ CORE ENGINE METHODS ~~~~~~~~~~~~~*/
t_texure_manager	*create_texure_manager(void);
int				init_texure_manager(t_texure_manager *texure_manager);
int				destroy_texure_manager(t_texure_manager *texure_manager);

int	texture_transform(t_image *texture, t_ray *ray, t_image *img);
int		init_texture(t_data *data);

#endif
