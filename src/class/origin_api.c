/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin_api.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:55:47 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 14:23:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "origin.h"
#include "game.h"
#include "settings.h"
#include "../../lib/libgc/include/libgc.h"

const t_origin_api	g_my_origin_api = {
	.create_game = create_game,
	.create_settings = create_settings,
	.destroy = destroy_program
};

t_origin	*create_program(void)
{
	t_origin *program = gc_malloc(sizeof(t_origin));
	if (!program)
	{
		fprintf(stderr, "[Origin Error] Failed to allocate t_origin.\n");
		return NULL;
	}
	gc_lock(program);
	program->title = GAME_TITLE;
	program->methods = &g_my_origin_api;
	printf("[Origin Debug] Created Origin program with title: %s\n", program->title);
	return program;
}

int	destroy_program(t_origin *program)
{
	if (!program)
		return (1);
	printf("[Origin Debug] Destroying Origin: %s\n", program->title);
	gc_free(program);
	return (0);
}
