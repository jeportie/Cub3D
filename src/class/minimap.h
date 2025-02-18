/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:17:44 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 14:33:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "game_object.h"
# include "game.h"

typedef struct s_minimap
{
	t_game_object	object;
	float			scale;
	int				width;
	int				height;
	int				offset_x;
	int				offset_y;
	float			smooth_x;
	float			smooth_y;
}				t_minimap;

t_minimap	*create_minimap(void);
int			init_minimap(t_minimap *minimap);
int			render_minimap(t_minimap *minimap, t_game *game, int buffer_to_draw);
int			destroy_minimap(t_minimap *minimap);

#endif
