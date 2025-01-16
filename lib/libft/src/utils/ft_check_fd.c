/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:34:20 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:42:41 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_check_fd(int fd, const char *error_message)
{
	if (fd == ERROR)
	{
		perror(error_message);
		exit(EXIT_FAILURE);
	}
}
