/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:55:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 17:42:13 by jeportie         ###   ########.fr       */
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

	printf("we enter here\n");
	total_len = 0;
	i = 0;
	while (i <= nb)
	{
		printf("strlen[%d] ->\n", i);
		total_len += ft_strlen(strs[i]);
		printf("strlen[%d] ok\n", i);
		i++;
	}
	printf("strlen ok\n");
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
	printf("we exit here\n");
	return (result);
}
