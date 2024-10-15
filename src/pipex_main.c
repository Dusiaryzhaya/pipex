/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:24:49 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/15 14:14:16 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// < file1.txt grep example | wc -w > outfile.txt && cat outfile.txt
// ./pipex file1.txt "grep example" "wc -w" outfile2.txt && cat outfile2.txt

//  < file1.txt ls -l | wc -l > outfile.txt && cat outfile.txt
// ./pipex file1.txt "ls -l" "wc -l" outfile2.txt && cat outfile2.txt

// < file1.txt grep Hello | ls -la src/ > outfile.txt && cat outfile.txt
// ./pipex file1.txt "grep Hello" "ls -la src/" outfile2.txt && cat outfile2.txt

void	execute_cmd1(int file1, int *fd, t_args *arg_list, char *envp[])
{
	char	*full_path;

	full_path = find_full_path(arg_list->cmd1_args[0], arg_list, envp);
	if (!full_path)
		error_msg(arg_list->cmd1_args[0], arg_list, 0);
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file1);
	execve(full_path, arg_list->cmd1_args, envp);
	error_msg(arg_list->cmd1_args[0], arg_list, 0);
}

void	execute_cmd2(int file2, int *fd, t_args *arg_list, char *envp[])
{
	char	*full_path;

	full_path = find_full_path(arg_list->cmd2_args[0], arg_list, envp);
	if (!full_path)
		error_msg(arg_list->cmd2_args[0], arg_list, 0);
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(file2);
	execve(full_path, arg_list->cmd2_args, envp);
	error_msg(arg_list->cmd2_args[0], arg_list, 0);
}

void	main_process(t_args *arg_list, char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error_msg("Pipe failed", arg_list, 1);
	pid = fork();
	if (pid == -1)
		error_msg("Fork failed", arg_list, 1);
	if (pid == 0)
		execute_cmd1(arg_list->file1, fd, arg_list, envp);
	pid = fork();
	if (pid == -1)
		error_msg("Fork failed", arg_list, 1);
	if (pid == 0)
		execute_cmd2(arg_list->file2, fd, arg_list, envp);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_args	arg_list;

	if (check_args_num(argc))
	{
		perror("The number of arguments must be 4.");
		exit(EXIT_FAILURE);
	}
	arg_list.cmd1_args = NULL;
	arg_list.cmd2_args = NULL;
	check_file_readable(argv[1], &arg_list);
	check_file_writable(argv[4], &arg_list);
	arg_list.cmd1_args = ft_split(argv[2], ' ');
	arg_list.cmd2_args = ft_split(argv[3], ' ');
	main_process(&arg_list, envp);
	free_args(&arg_list);
	return (0);
}
