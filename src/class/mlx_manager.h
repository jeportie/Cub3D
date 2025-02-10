/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:12:42 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 23:17:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGER_H
# define MLX_MANAGER_H

# include "graphic_engine.h"

typedef struct s_graphic_engine_api	t_graphic_engine_api;
typedef struct s_graphic_engine		t_graphic_engine;

typedef struct s_mlx_manager_api
{
	t_graphic_engine_api	base;
}				t_mlx_manager_api;

extern const t_mlx_manager_api		g_mlx_manager_methods;

typedef struct s_mlx_manager
{
	t_graphic_engine		base;

	t_xvar			*mlx_ptr;
	void			*win_ptr;

	const t_mlx_manager_api	*methods;
}				t_mlx_manager;

/* ~~~~~~~~~~~ MLX MANAGER METHODS ~~~~~~~~~~~~~*/
t_mlx_manager	*create_mlx_manager(void);
int				init_mlx_manager(t_mlx_manager *mlx_manager);
int				run_mlx_manager(t_mlx_manager *mlx_manager);
int				destroy_mlx_manager(t_mlx_manager *mlx_manager);

#endif
