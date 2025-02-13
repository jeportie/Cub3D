/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:29:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 21:00:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/origin.h"
#include "src/class/game.h"
#include "src/class/settings.h"

int	main(void)
{
	t_origin	*program;
	t_game		*game;
	t_settings	*settings;

	program = create_program();
	printf("[Main Debug] Program pointer = %p\n", (void *)program);
	game = program->methods->create_game();
	if (!game)
	{
		ft_dprintf(2, "[Main Error] Failed to create Game.\n");
		return (1);
	}
	settings = program->methods->create_settings();
	if (!settings)
	{
		ft_dprintf(2, "[Main Error] Failed to create Settings.\n");
		return (1);
	}
	game->settings = settings;
	settings->game = game;
	settings->methods->init(settings);
	game->methods->init(game);
	game->methods->run(game);
	game->methods->destroy(game);
	program->methods->destroy(program);
	return (0);
}
