/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:29:39 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/15 12:42:56 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all_paths(char **all_paths)
{
	int	i;

	i = 0;
	while (all_paths[i])
	{
		free(all_paths[i]);
		i++;
	}
	free(all_paths);
}

void	free_list(t_args *arg_list)
{
	int	i;

	if (arg_list->cmd1_args != NULL)
	{
		i = 0;
		while (arg_list->cmd1_args[i] != NULL)
		{
			free(arg_list->cmd1_args[i]);
			i++;
		}
		free(arg_list->cmd1_args);
		arg_list->cmd1_args = NULL;
	}
	if (arg_list->cmd2_args != NULL)
	{
		i = 0;
		while (arg_list->cmd2_args[i] != NULL)
		{
			free(arg_list->cmd2_args[i]);
			i++;
		}
		free(arg_list->cmd2_args);
		arg_list->cmd2_args = NULL;
	}
}

void	free_args(t_args *arg_list)
{
	if (arg_list->cmd1_args != NULL || arg_list->cmd2_args != NULL)
	{
		free_list(arg_list);
	}
	if (arg_list->file1 >= 0)
	{
		close(arg_list->file1);
		arg_list->file1 = -1;
	}
	if (arg_list->file2 >= 0)
	{
		close(arg_list->file2);
		arg_list->file2 = -1;
	}
}
