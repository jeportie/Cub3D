/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:15:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/14 22:34:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_engine.h"
#include "../../include/error.h"

t_mlx_app	*mlx_app_create(int width, int height, const char *title)
{
	t_mlx_app	*app;

	app = gc_malloc(sizeof(t_mlx_app));
	if (!app)
	{
		ft_dprintf(2, ERR_MALLOC);
		return (NULL);
	}
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
	{
		ft_dprintf(2, ERR_NO_X_DISPLAY);
		return (NULL);
	}
	app->win_ptr = mlx_new_window(app->mlx_ptr, width, height, (char *)title);
	if (!app->win_ptr)
	{
		ft_dprintf(2, ERR_WINDOW_CREATION);
		mlx_destroy_display(app->mlx_ptr);
		return (NULL);
	}
	ft_printf(DEB_MLX_APP_CREATE);
	return (app);
}
