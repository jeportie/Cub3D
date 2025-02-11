/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:58:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 22:31:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_MANAGER_H
# define INPUT_MANAGER_H

# include "../class/game.h"

int	input_manager_init(t_game *game);
int	input_manager_shutdown(t_game *game);
int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_game *game);

#endif
