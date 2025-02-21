/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:40:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/28 15:43:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODES_H
# define MODES_H

# include "cub3d.h"

int	re_init_game(t_data *data, bool plane_mode);
int	angle_init_game(t_data *data);
int	plane_init_game(t_data *data);

#endif /*MODES_H*/
