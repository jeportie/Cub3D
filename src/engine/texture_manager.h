/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:21:26 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 18:21:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_MANAGER_H
# define TEXTURE_MANAGER_H

# include "graphic_engine.h"

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
int					texture_transform(t_image *texture, t_ray *ray,
						t_image *img);
int					init_texture(t_graphics *engine);

#endif
