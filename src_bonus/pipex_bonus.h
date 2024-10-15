/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:45:46 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/15 13:07:24 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPEX_BONUS_H
#ifdef PIPEX_BONUS_H

# include "../libft/src/ft_printf.h"
# include "../libft/src/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define PATH "./usr/bin/"

typedef struct s_pipe_fds
{
	int					fd[2];
	int					fd_prev[2];
}						t_pipe_fds;

typedef struct s_command
{
	char				**args;
	struct s_command	*next;
}						t_command;

typedef struct s_args
{
	char				*file1_name;
	int					file1;
	int					file2;
	char				*limiter;
	int					heredoc_calling;
	t_command			*cmd_list;
}						t_args;

/* ************************************************************************** */
/*                             Cleanup functions                              */
/* ************************************************************************** */

void					free_args(t_args *arg_list);
void					free_all_paths(char **all_paths);

/* ************************************************************************** */
/*                             Support functions                              */
/* ************************************************************************** */

void					error_msg(const char *str, t_args *arg_list,
							int error_type);
void					check_file_readable(const char *filename,
							t_args *arg_list);
void					check_file_writable(const char *filename,
							t_args *arg_list);
int						check_args_num(int argc);

/* ************************************************************************** */
/*                                   Heredoc                                  */
/* ************************************************************************** */

int						process_heredoc_args(int argc, char *argv[],
							t_args *arg_list, char *envp[]);

/* ************************************************************************** */
/*                               Common functions                             */
/* ************************************************************************** */

void					add_command(t_args *arg_list, char *cmd);
void					read_from_file(t_pipe_fds *fds, t_command *cmd,
							t_args *arg_list, char *envp[]);
void					write_to_file(t_pipe_fds *fds, t_command *cmd,
							t_args *arg_list, char *envp[]);
void					create_fork(int *pid, t_args *arg_list);

/* ************************************************************************** */
/*                                   Get path                                 */
/* ************************************************************************** */

char					*find_full_path(const char *cmd, t_args *arg_list,
							char *envp[]);

#endif