/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin_api.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:55:47 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 16:36:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "origin.h"
#include "game.h"
#include "settings.h"

const t_origin_api	g_origin_methods = {
	.create_game = create_game,
	.create_settings = create_settings,
	.destroy = destroy_program
};

t_origin	*create_program(void)
{
	t_origin	*program;

	program = gc_malloc(sizeof(t_origin));
	if (!program)
	{
		fprintf(stderr, "[Origin Error] Failed to allocate t_origin.\n");
		return (NULL);
	}
	gc_lock(program);
	program->title = GAME_TITLE;
	program->methods = &g_origin_methods;
	ft_printf("[Origin Debug] Created Origin program with title: %s\n",
		program->title);
	return (program);
}

int	destroy_program(t_origin *program)
{
	if (!program)
		return (1);
	printf("[Origin Debug] Destroying Origin: %s\n", program->title);
	gc_free(program);
	return (0);
}
