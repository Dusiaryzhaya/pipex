/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:52:35 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/15 14:22:04 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	t_command	*cur;
	t_command	*next;
	int			i;

	cur = arg_list->cmd_list;
	while (cur != NULL)
	{
		next = cur->next;
		i = 0;
		while (cur->args[i])
		{
			free(cur->args[i]);
			i++;
		}
		free(cur->args);
		free(cur);
		cur = next;
	}
}

void	free_args(t_args *arg_list)
{
	if (arg_list->cmd_list != NULL)
	{
		free_list(arg_list);
	}
	if (arg_list->file1_name)
	{
		arg_list->file1_name = NULL;
	}
	if (arg_list->file1 >= 0)
	{
		close(arg_list->file1);
	}
	if (arg_list->file2 >= 0)
	{
		close(arg_list->file2);
	}
	free(arg_list);
}
