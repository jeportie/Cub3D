/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:34:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:34:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"
#include "../../include/libft.h"

void	ft_perror(t_error error)
{
	if (error == NOERR)
		ft_putstr_fd("Succes\n", 2);
	else if (error == ERNOWRITE)
		ft_putstr_fd("Error: Failed to write output\n", 2);
	else if (error == ERNOMEM)
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
	else if (error == ERNOFORMAT)
		ft_putstr_fd("Error: Invalid format string\n", 2);
}
