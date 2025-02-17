/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cmd_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:12:59 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:43:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_concat_path(char **paths, const char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		ft_check_malloc(cmd_path, "Strjoin Error !\n");
		cmd_path = ft_strjoin_free(cmd_path, cmd);
		ft_check_malloc(cmd_path, "Strjoin Error !\n");
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*ft_find_cmd_path(char **envp, const char *cmd)
{
	char	**paths;
	char	*path_env;

	path_env = ft_getenv(envp, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (ft_concat_path(paths, cmd));
}
