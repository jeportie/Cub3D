/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:47:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:16:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*modified_str;
	size_t	strlen;
	size_t	i;

	if (!s || !f)
		return (NULL);
	strlen = ft_strlen(s);
	modified_str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!modified_str)
		return (NULL);
	i = 0;
	while (i < strlen)
	{
		modified_str[i] = f(i, s[i]);
		i++;
	}
	modified_str[i] = '\0';
	return (modified_str);
}
