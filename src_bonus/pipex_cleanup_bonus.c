/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:52:35 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/09 15:52:54 by anilchen         ###   ########.fr       */
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
	t_command	*current;
	t_command	*next;
	int			i;

	current = arg_list->cmd_list;
	while (current != NULL)
	{
		next = current->next;
		i = 0;
		while (current->args[i])
		{
			free(current->args[i]);
			i++;
		}
		free(current->args);
		free(current);
		current = next;
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
