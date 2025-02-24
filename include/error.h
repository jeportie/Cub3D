/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:33:11 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 11:25:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_GETTIME "Error: clock_gettime() failed.\n"
# define ERR_MLX_INIT "Error: mlx_init() failed.\n"
# define ERR_MLX_WINDOW "Error: mlx_new_window() failed.\n"
# define ERR_MLX_IMAGE "Error: mlx_new_image() failed.\n"
# define ERR_MLX_DATA "Error: mlx_get_data_addr() failed.\n"
# define ERR_TEX_INIT "Error: Texture initialization failed.\n"
# define ERR_MLX_TEX "Error: could not load texture from %s\n"

#endif
