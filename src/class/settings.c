/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:53:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/15 10:24:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/define.h"
#include "settings.h"

const t_settings_api	g_settings_methods = {
	.init = init_settings,
	.destroy = destroy_settings};

t_settings	*create_settings(void)
{
	t_settings	*settings;

	settings = gc_malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	ft_printf(DEB_SET_CREATE);
	settings->methods = &g_settings_methods;
	return (settings);
}

int	init_settings(t_settings *settings)
{
	ft_printf(DEB_SET_INIT);
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
	if (!settings)
		return (-1);
	ft_printf(DEB_SET_DESTROY);
	return (0);
}
