/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:05:56 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/09 15:50:47 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// test_heredoc
// cat << END | wc -l >> heredoc.txt && cat heredoc.txt
// ./pipex_bonus here_doc "END" "cat" "wc -l" heredoc2.txt  && cat heredoc2.txt

static char	*read_string(void)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (ft_strdup(buffer));
}

void	here_doc(char *limiter, t_args *arg_list)
{
	char	*data;

	while (1)
	{
		ft_printf("heredoc> ");
		data = read_string();
		if (ft_strncmp(data, limiter, ft_strlen(limiter)) == 0
			&& data[ft_strlen(limiter)] == '\n')
		{
			free(data);
			break ;
		}
		write(arg_list->file1, data, ft_strlen(data));
		free(data);
	}
}

void	heredoc_pipex(t_args *arg_list, char *envp[])
{
	pid_t		pid;
	t_command	*cur_cmd;
	t_pipe_fds	fds;

	cur_cmd = arg_list->cmd_list;
	if (pipe(fds.fd) == -1)
		error_msg("Pipe failed", arg_list, 1);
	here_doc(arg_list->limiter, arg_list);
	create_fork(&pid, arg_list);
	if (pid == 0)
		read_from_file(&fds, cur_cmd, arg_list, envp);
	cur_cmd = cur_cmd->next;
	create_fork(&pid, arg_list);
	if (pid == 0)
		write_to_file(&fds, cur_cmd, arg_list, envp);
	close(fds.fd[0]);
	close(fds.fd[1]);
	wait(NULL);
	wait(NULL);
}

int	process_heredoc_args(int argc, char *argv[], t_args *arg_list, char *envp[])
{
	int	i;

	i = 3;
	arg_list->limiter = argv[2];
	arg_list->file1 = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	arg_list->heredoc_calling = 1;
	check_file_writable(argv[argc - 1], arg_list);
	while (i < argc - 1)
	{
		add_command(arg_list, argv[i]);
		i++;
	}
	heredoc_pipex(arg_list, envp);
	unlink(arg_list->file1_name);
	free_args(arg_list);
	return (0);
}
