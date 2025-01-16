/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:43:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:54:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_substr;
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	dst_len = len;
	if (src_len - start < len)
		dst_len = src_len - start;
	new_substr = (char *)malloc(sizeof(char) * (dst_len + 1));
	if (!new_substr)
		return (NULL);
	i = 0;
	while (i < dst_len)
	{
		new_substr[i] = s[start + i];
		i++;
	}
	new_substr[i] = '\0';
	return (new_substr);
}
