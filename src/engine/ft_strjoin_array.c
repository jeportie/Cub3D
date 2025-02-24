/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:55:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 10:23:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

char	*ft_strjoin_array(char **strs, int nb)
{
	int		i;
	int		j;
	int		k;
	int		total_len;
	char	*result;

	total_len = 0;
	i = -1;
	while (++i <= nb)
		total_len += ft_strlen(strs[i]);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (i <= nb)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		i++;
	}
	result[k] = '\0';
	return (result);
}
