/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:07:23 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/14 19:58:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEB_PRG_PTR 		"[Program Debug]\tProgram pointer = %p\n"
# define DEB_PRG_CREATE		"[Program Debug]\tFunction: create_program() called with title: %s\n"
# define DEB_PRG_DESTROY	"[Program Debug]\tFunction: destroy_program() called!\n"

# define DEB_GAME_CREATE	"[Game Debug]\tFunction: create_game() called!\n"
# define DEB_GAME_INIT		"[Game Debug]\tFunction: init_game() called!\n"
# define DEB_GAME_OBJ_INIT	"[Game Debug]\tAll object init and print: ok!\n"
# define DEB_GAME_RUN		"[Game Debug]\tFunction: run_game() called!\n"
# define DEB_GAME_MLX_LOOP	"[Game Debug]\tEntering MLX event loop!\n"
# define DEB_GAME_DESTROY	"[Game Debug]\tFunction: destroy_game() called!\n"
# define DEB_GAME_ESC		"[Game Debug]\tESC pressed. Exiting.\n"

# define DEB_CORE_CREATE	"[Core Debug]\tFunction: create_core_engine() called!\n"
# define DEB_CORE_INIT		"[Core Debug]\tFunction: core_engine_init() called!\n"

#endif
