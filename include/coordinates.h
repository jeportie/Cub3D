/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:41:28 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 20:41:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES_H
# define COORDINATES_H

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_transform
{
	double	x;
	double	y;
	double	angle;
	double	dx;
	double	dy;
}				t_transform;

#endif
