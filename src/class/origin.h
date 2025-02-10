/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:50:39 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 14:23:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORIGIN_H
# define ORIGIN_H

# include "../../include/cub3d.h"

/*
 * The Origin class is our root/base object.
 * We store the standard pointer to 'g_origin_methods' 
 * plus any members we want in the future.
 */

typedef struct s_origin_api
{
	t_game		*(*create_game)(void);
	t_settings	*(*create_settings)(struct s_game *game);
	int			(*destroy)(struct s_origin *self);
}				t_origin_api;

typedef struct s_origin
{
	const char			*title;
	const t_origin_api	*methods;
}			t_origin;

extern const t_origin_api	g_origin_methods;

t_origin	*create_program(void);
int			destroy_program(t_origin *program);

#endif
