/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:07:23 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/14 22:45:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEB_PRG_PTR 		"[Program Debug]\t\tProgram pointer = %p\n"
# define DEB_PRG_CREATE		"[Program Debug]\t\tFunction: create_program() called with title: %s\n"
# define DEB_PRG_DESTROY	"[Program Debug]\t\tFunction: destroy_program() called!\n"

# define DEB_GAME_CREATE	"[Game Debug]\t\tFunction: create_game() called!\n"
# define DEB_GAME_INIT		"[Game Debug]\t\tFunction: init_game() called!\n"
# define DEB_GAME_OBJ_INIT	"[Game Debug]\t\tAll object init and print: ok!\n"
# define DEB_GAME_RUN		"[Game Debug]\t\tFunction: run_game() called!\n"
# define DEB_GAME_MLX_LOOP	"[Game Debug]\t\tEntering MLX event loop!\n"
# define DEB_GAME_DESTROY	"[Game Debug]\t\tFunction: destroy_game() called!\n"
# define DEB_GAME_ESC		"[Game Debug]\t\tESC pressed. Exiting.\n"

# define DEB_CORE_CREATE	"[Core Debug]\t\tFunction: create_core_engine() called!\n"
# define DEB_CORE_INIT		"[Core Debug]\t\tFunction: core_engine_init() called!\n"

# define DEB_GRAPHIC_CREATE	"[Graphic Debug]\t\tFunction: create_graphic_engine() called!\n"
# define DEB_GRAPHIC_INIT	"[Graphic Debug]\t\tFunction: graphic_engine_init() called!\n"

# define DEB_MLX_APP_CREATE	"[Mlx Debug]\t\tMLX initialized and window created.\n"

# define DEB_CALLB_CREATE	"[Callback Debug]\tFunction: create_input_manager() called!\n"
# define DEB_CALLB_INIT		"[Callback Debug]\tFunction: input_manager_init() called!\n"
# define DEB_CALLB_PRESS	"[Callback Debug]\tKey Pressed = %d\n"
# define DEB_CALLB_RELEASE	"[Callback Debug]\tKey Released = %d\n"

# define DEB_MAP_CREATE		"[Map Debug]\t\tFunction: create_map() called!\n"
# define DEB_MAP_INIT		"[Map Debug]\t\tFunction: init_map() called!\n"
# define DEB_MAP_RENDER		"[Map Debug]\t\tFunction: map_render() called!\n"
# define DEB_MAP_PRINT		"[Map Debug]\t\tFunction: print_map() called!.\nMap layout (0=floor, 1=wall, P=player):\n\n"
# define DEB_MAP_DESTROY	"[Map Debug] destroy_map() called\n"

#endif
