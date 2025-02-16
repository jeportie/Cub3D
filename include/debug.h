/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:07:23 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 11:27:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEB_PRG_PTR 		"[Program Object]\tProgram pointer = %p\n"
# define DEB_PRG_CREATE		"[Program Object]\tFunction: create_program() " \
							"called with title: %s\n"
# define DEB_PRG_DESTROY	"[Program Object]\tFunction: destroy_program() called!\n"

# define DEB_SET_CREATE		"[Settings Object]\tFunction: create_settings() called!\n"
# define DEB_SET_INIT		"[Settings Object]\tFunction: init_settings() called!\n"
# define DEB_SET_DESTROY	"[Settings Object]\tFunction: destroy_settings() called!\n"

# define DEB_GAME_CREATE	"[Game Object]\t\tFunction: create_game() called!\n"
# define DEB_GAME_INIT		"[Game Object]\t\tFunction: init_game() called!\n"
# define DEB_GAME_OBJ_INIT	"[Game Object]\t\tAll object init and print: ok!\n"
# define DEB_GAME_RUN		"[Game Object]\t\tFunction: run_game() called!\n"
# define DEB_GAME_MLX_LOOP	"[Game Object]\t\tEntering MLX event loop!\n"
# define DEB_GAME_DESTROY	"[Game Object]\t\tFunction: destroy_game() called!\n"
# define DEB_GAME_ESC		"[Game Object]\t\tESC pressed. Exiting.\n"

# define DEB_CORE_CREATE	"[Core Eninge]\t\tFunction: create_core_engine() called!\n"
# define DEB_CORE_INIT		"[Core Engine]\t\tFunction: core_engine_init() called!\n"

# define DEB_GRAPHIC_CREATE	"[Graphic Engine]\tFunction: create_graphic_engine() called!\n"
# define DEB_GRAPHIC_INIT	"[Graphic Engine]\tFunction: graphic_engine_init() called!\n"

# define DEB_MLX_APP_CREATE	"[Mlx Manager]\t\tMLX initialized and window created!\n"

# define DEB_CALLB_CREATE	"[Callback System]\tFunction: create_input_manager() called!\n"
# define DEB_CALLB_INIT		"[Callback System]\tFunction: input_manager_init() called!\n"
# define DEB_CALLB_PRESS	"[Callback System]\tKey Pressed = %d\n"
# define DEB_CALLB_RELEASE	"[Callback System]\tKey Released = %d\n"

# define DEB_MAP_CREATE		"[Map Object]\t\tFunction: create_map() called!\n"
# define DEB_MAP_INIT		"[Map Object]\t\tFunction: init_map() called!\n"
# define DEB_MAP_RENDER		"[Map Object]\t\tFunction: map_render() called!\n"
# define DEB_MAP_PRINT		"[Map Object]\t\tFunction: print_map() called!\n" \
							"[Map layout]\t\t(0=floor, 1=wall, P=player):\n\n"
# define DEB_MAP_DESTROY	"[Map Object]\t\tFunction: destroy_map() called!\n"

# define DEB_PLAYER_CREATE	"[Player Object]\t\tFunction: create_player() called!\n"
# define DEB_PLAYER_INIT	"[Player Object]\t\tFunction: init_player() called!\n"
# define DEB_PLAYER_DESTROY	"[Player Object]\t\tFunction: destroy_player() called!\n"

#endif
