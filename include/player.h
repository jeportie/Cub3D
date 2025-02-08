/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:23:30 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/07 18:09:41 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_data t_data;

# include <stdbool.h>

int	player_init(t_data *data);
int	player_update(t_data *data, double delta_time);

#endif
