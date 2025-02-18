/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_debug_log.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:26:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 13:03:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/game.h"

int	debug_log_add(t_debug_log *log, const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	vsnprintf(log->lines[log->write_index], MAX_LINE_LENGTH, fmt, args);
	va_end(args);
	log->write_index = (log->write_index + 1) % MAX_DEBUG_LINES;
	log->total_lines++;
	return (0);
}

int	init_debug_log(t_game *game)
{
	ft_memset(&game->debug_log, 0, sizeof(game->debug_log));
	game->debug_log.write_index = 0;
	game->debug_log.total_lines = 0;
	return (0);
}

int	draw_debug_log(void *mlx_ptr, void *win_ptr, t_debug_log *log)
{
    int base_x = 20;
    int base_y = 600;
    int line_spacing = 20;

    int max_lines_to_show = MAX_DEBUG_LINES;
    int start = log->write_index % MAX_DEBUG_LINES;

    for (int i = 0; i < max_lines_to_show; i++)
    {
        int index = (start + i) % MAX_DEBUG_LINES;
        if (log->lines[index][0] == '\0')
            continue;
        int x = base_x;
        int y = base_y + (i * line_spacing);
        mlx_string_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF, log->lines[index]);
    }
	return (0);
}
