/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:24:49 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/14 13:35:05 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// < file1.txt cat | grep "example" | wc -l > outfile.txt && cat outfile.txt
// ./pipex_bonus file1.txt "cat" "grep example" "wc -l" outfile2.txt
//	&& cat outfile2.txt

//  < file1.txt ls -l | grep "No" | wc -l > outfile.txt && cat outfile.txt
// ./pipex_bonus file1.txt "ls -l" "grep No" "wc -l" outfile2.txt
//	&& cat outfile2.txt

// < file1.txt tr -d ! | grep -v ! | sed 's/Hello/Salut/g' | grep Salut | wc
//	-l > outfile.txt&& cat outfile.txt
// ./pipex_bonus file1.txt "tr -d \!" "grep
//	-v \!" "sed s/Hello/Salut/g" "grep Salut" "wc -l" outfile2.txt
//	&& cat outfile2.txt

void	execute_middle_cmd(t_pipe_fds *fds, t_command *cmd, t_args *arg_list,
		char *envp[])
{
	char	*full_path;

	full_path = find_full_path(cmd->args[0], arg_list, envp);
	if (!full_path)
	{
		error_msg(cmd->args[0], arg_list, 0);
	}
	dup2(fds->fd_prev[0], STDIN_FILENO);
	dup2(fds->fd[1], STDOUT_FILENO);
	close(fds->fd_prev[0]);
	close(fds->fd_prev[1]);
	close(fds->fd[0]);
	close(fds->fd[1]);
	execve(full_path, cmd->args, envp);
	error_msg(cmd->args[0], arg_list, 0);
}

void	process_middle_cmd(t_pipe_fds *fds, t_command **cur_cmd,
		t_args *arg_list, char *envp[])
{
	pid_t	pid;

	fds->fd_prev[0] = fds->fd[0];
	fds->fd_prev[1] = fds->fd[1];
	if (pipe(fds->fd) == -1)
	{
		error_msg("Pipe failed", arg_list, 1);
	}
	create_fork(&pid, arg_list);
	if (pid == 0)
	{
		execute_middle_cmd(fds, *cur_cmd, arg_list, envp);
	}
	close(fds->fd_prev[0]);
	close(fds->fd_prev[1]);
	*cur_cmd = (*cur_cmd)->next;
}

void	main_bonus_process(t_args *arg_list, char *envp[])
{
	pid_t		pid;
	t_command	*cur_cmd;
	t_pipe_fds	fds;

	cur_cmd = arg_list->cmd_list;
	if (pipe(fds.fd) == -1)
		error_msg("Pipe failed", arg_list, 1);
	create_fork(&pid, arg_list);
	if (pid == 0)
		read_from_file(&fds, cur_cmd, arg_list, envp);
	cur_cmd = cur_cmd->next;
	while (cur_cmd->next != NULL)
	{
		process_middle_cmd(&fds, &cur_cmd, arg_list, envp);
	}
	create_fork(&pid, arg_list);
	if (pid == 0)
		write_to_file(&fds, cur_cmd, arg_list, envp);
	close(fds.fd[0]);
	close(fds.fd[1]);
	while (wait(NULL) > 0)
		;
}

void	assign_vars(t_args *arg_list, char *argv[])
{
	arg_list->cmd_list = NULL;
	arg_list->heredoc_calling = 0;
	arg_list->file1_name = argv[1];
}

int	main(int argc, char *argv[], char *envp[])
{
	t_args	*arg_list;
	int		i;

	i = 2;
	if (argc < 5)
	{
		perror("The number of arguments must be at least 4.");
		exit(EXIT_FAILURE);
	}
	arg_list = (t_args *)malloc(sizeof(t_args));
	if (!arg_list)
		exit(1);
	assign_vars(arg_list, argv);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (process_heredoc_args(argc, argv, arg_list, envp));
	check_file_readable(arg_list->file1_name, arg_list);
	check_file_writable(argv[argc - 1], arg_list);
	while (i < argc - 1)
	{
		add_command(arg_list, argv[i]);
		i++;
	}
	main_bonus_process(arg_list, envp);
	free_args(arg_list);
	return (0);
}
