/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:35:43 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:06:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	total_size;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	total_size = nmemb * size;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, total_size);
	return (memory);
}
