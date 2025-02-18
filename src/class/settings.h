/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:03:30 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 14:36:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include "origin.h"

typedef struct s_settings_api
{
	t_origin_api	base;
	int				(*init)(struct s_settings *self);
	int				(*destroy)(struct s_settings *self);
}				t_settings_api;

extern const t_settings_api	g_settings_methods;

typedef struct s_settings
{
	t_origin				base;

	t_game					*game;
	int						window_width;
	int						window_height;
	bool					toogle_rays;
	bool					toogle_texture;
	bool					toogle_map;
	bool					toogle_minimap;
	bool					toogle_dda;

	const t_settings_api	*methods;
}			t_settings;

t_settings	*create_settings(void);
int			init_settings(t_settings *settings);
int			destroy_settings(t_settings *settings);

#endif
