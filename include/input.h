/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:22:54 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/20 22:44:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "cub3d.h"

int	key_press(int keycode, t_data *data);
int	key_release(int keycode, t_data *data);

#endif
