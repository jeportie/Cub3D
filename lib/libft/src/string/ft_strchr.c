/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:53 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:14:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	first_occurrence;

	first_occurrence = (unsigned char)c;
	while (*s)
	{
		if (*s == first_occurrence)
			return ((char *)s);
		s++;
	}
	if (first_occurrence == '\0')
		return ((char *)s);
	return (NULL);
}
