/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_get_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:57:38 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/14 15:07:05 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char *name, char *envp[])
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
		{
			j++;
		}
		if (ft_strncmp(envp[i], name, j) == 0 && name[j] == '\0')
		{
			return (envp[i] + j + 1);
		}
		i++;
	}
	return (NULL);
}

char	*find_full_path(const char *cmd, t_args *arg_list, char *envp[])
{
	char	*cmd_path;
	char	**all_paths;
	char	*path_with_slash;
	int		i;
	char	*env_path;

	i = 0;
	env_path = get_env("PATH", envp);
	all_paths = ft_split(env_path, ':');
	while (all_paths[i] != NULL)
	{
		path_with_slash = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(path_with_slash, cmd);
		free(path_with_slash);
		if (access(cmd_path, X_OK) == 0)
		{
			free_all_paths(all_paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_all_paths(all_paths);
	error_msg(cmd, arg_list, 0);
	return (0);
}
