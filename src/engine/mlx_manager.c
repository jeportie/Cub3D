/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:15:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 18:15:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manager.h"
#include "../../lib/minilibx/mlx.h"
#include "../../lib/minilibx/mlx_int.h"

const t_mlx_manager_api	g_mlx_manager_methods = {
	.init = init_mlx_manager,
	.destroy = destroy_mlx_manager
};

t_mlx	*mlx_app_create(int width, int height, const char *title)
{
	t_mlx	*app;

	app = malloc(sizeof(t_mlx));
	if (!app)
	{
		fprintf(stderr, ERR_MALLOC);
		return (NULL);
	}
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
	{
		fprintf(stderr, ERR_NO_X_DISPLAY);
		free(app);
		return (NULL);
	}
	app->win_ptr = mlx_new_window(app->mlx_ptr, width, height, (char *)title);
	if (!app->win_ptr)
	{
		fprintf(stderr, ERR_WINDOW_CREATION);
		mlx_destroy_display(app->mlx_ptr);
		free(app);
		return (NULL);
	}
	ft_printf("MLX initialized and window created.\n");
	return (app);
}
