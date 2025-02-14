/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:56:20 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/14 19:51:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "origin.h"
#include "game.h"
#include "settings.h"
#include <error.h>

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
		ft_dprintf(2, ERR_ORIGIN_INIT);
		return (NULL);
	}
	gc_lock(program);
	program->title = GAME_TITLE;
	program->methods = &g_origin_methods;
	ft_printf(DEB_PRG_CREATE, program->title);
	return (program);
}

int	destroy_program(t_origin *program)
{
	if (!program)
		return (1);
	printf(DEB_PRG_DESTROY);
	gc_free(program);
	return (0);
}
