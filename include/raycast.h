/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:58:03 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 20:58:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef struct s_ray
{
    float rx;
    float ry;
    float dist;
}   t_ray;

int draw_rays(t_data *data);

#endif

