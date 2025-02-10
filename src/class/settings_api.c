/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_api.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:14:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 18:12:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/define.h"
#include "settings.h"

const t_settings_api	g_settings_methods = {
	.init = init_settings,
	.destroy = destroy_settings};

t_settings	*create_settings(t_game *game)
{
	t_settings	*settings;

	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->methods = &g_settings_methods;

	return (settings);
}

int	init_settings(t_settings *settings)
{
	settings->window_width = WINDOW_WIDTH;
	settings->window_height = WINDOW_HEIGHT;
	settings->toogle_map = true;
	settings->toogle_dda = true;
	settings->toogle_rays = true;
	settings->toogle_texture = false;
	return (0);
}

int	destroy_settings(t_settings *settings)
{
	return (1);
}
