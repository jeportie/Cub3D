/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:29:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 14:34:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/define.h"
#include "src/class/origin.h"
#include "src/class/game.h"
#include "src/class/settings.h"

char	g_map[MAP_SIZE + 1] = {
	"11111001"
	"10000001"
	"10000001"
	"10011001"
	"10010001"
	"1000P001"
	"10000001"
	"11111111"
};

int	main(void)
{
	t_origin	*program;
	t_game		*game;
	t_settings	*settings;

	program = create_program();
	printf("[Main Debug] Program pointer = %p\n", (void *)program);
	game = program->methods->create_game();
	settings = program->methods->create_settings(game);
//	settings->methods->init(game->settings);
//	game->methods->init(game);
//	game->methods->run(game);
//	game->methods->destroy(game);
	program->methods->destroy(program);
	return (0);
}
