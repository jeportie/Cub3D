/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:56:56 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 22:42:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*    A simple base class for all game objects (Player, Map, etc.)            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_H
# define GAME_OBJECT_H

# include "../../include/cub3d.h"

typedef struct s_methods
{
	int	(*init)(t_game_object *self);
	int	(*print)(void);	
	int	(*update)(t_game_object *self, double dt);
	int	(*render)(t_game_object *self);
	int	(*destroy)(t_game_object *self);
}				t_methods;

typedef struct s_game_object
{
	const t_methods			*methods;
	bool					active;
}	t_game_object;

#endif /* GAME_OBJECT_H */
