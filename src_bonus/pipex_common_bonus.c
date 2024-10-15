/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_common_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:25:17 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/15 14:03:42 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	add_command(t_args *arg_list, char *cmd)
{
	t_command	*new_cmd;
	t_command	*current;

	new_cmd = malloc(sizeof(t_command));
	if (!new_cmd)
		error_msg("malloc", arg_list, 1);
	new_cmd->args = ft_split(cmd, ' ');
	if (!new_cmd->args)
	{
		free(new_cmd);
		error_msg("ft_split failed", arg_list, 1);
	}
	new_cmd->next = NULL;
	if (!arg_list->cmd_list)
		arg_list->cmd_list = new_cmd;
	else
	{
		current = arg_list->cmd_list;
		while (current->next)
			current = current->next;
		current->next = new_cmd;
	}
}

void	read_from_file(t_pipe_fds *fds, t_command *cmd, t_args *arg_list,
		char *envp[])
{
	char	*full_path;

	if (arg_list->heredoc_calling)
	{
		close(arg_list->file1);
		arg_list->file1 = open(arg_list->file1_name, O_RDONLY);
		if (arg_list->file1 == -1)
		{
			error_msg("Error reopening file1", arg_list, 1);
		}
	}
	full_path = find_full_path(cmd->args[0], arg_list, envp);
	if (!full_path)
	{
		error_msg(cmd->args[0], arg_list, 0);
	}
	dup2(arg_list->file1, STDIN_FILENO);
	dup2(fds->fd[1], STDOUT_FILENO);
	close(fds->fd[0]);
	close(fds->fd[1]);
	close(arg_list->file1);
	execve(full_path, cmd->args, envp);
	error_msg(cmd->args[0], arg_list, 0);
}

void	write_to_file(t_pipe_fds *fds, t_command *cmd, t_args *arg_list,
		char *envp[])
{
	char	*full_path;

	full_path = find_full_path(cmd->args[0], arg_list, envp);
	if (!full_path)
	{
		error_msg(cmd->args[0], arg_list, 0);
	}
	dup2(fds->fd[0], STDIN_FILENO);
	dup2(arg_list->file2, STDOUT_FILENO);
	close(fds->fd[1]);
	close(fds->fd[0]);
	close(arg_list->file2);
	execve(full_path, cmd->args, envp);
	error_msg(cmd->args[0], arg_list, 0);
}
