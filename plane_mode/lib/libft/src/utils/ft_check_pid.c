/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:42:57 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:42:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_check_pid(int pid)
{
	if (pid == ERROR)
	{
		perror("Forking Error !\n");
		exit(EXIT_FAILURE);
	}
}
