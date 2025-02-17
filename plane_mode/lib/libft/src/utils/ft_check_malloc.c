/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:35:53 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:42:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_check_malloc(void *ptr, const char *error_message)
{
	if (!ptr)
	{
		perror(error_message);
		exit(EXIT_FAILURE);
	}
}
