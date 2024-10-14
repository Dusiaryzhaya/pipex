/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_supp_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:40:29 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/14 15:22:34 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(const char *str, t_args *arg_list, int error_type)
{
	if (error_type == 0)
	{
		write(STDERR_FILENO, "pipex: command not found: ", 26);
		write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, "\n", 1);
	}
	else if (error_type == 1)
	{
		perror(str);
	}
	if (arg_list->cmd1_args || arg_list->cmd2_args)
	{
		free_args(arg_list);
	}
	exit(EXIT_SUCCESS);
}

void	check_file_readable(const char *filename, t_args *arg_list)
{
	if (access(filename, F_OK) != 0)
	{
		error_msg(filename, arg_list, 1);
	}
	if (access(filename, R_OK) != 0)
	{
		error_msg(filename, arg_list, 1);
	}
	arg_list->file1 = open(filename, O_RDONLY);
	if (arg_list->file1 == -1)
	{
		error_msg(filename, arg_list, 1);
	}
}

void	check_file_writable(const char *filename, t_args *arg_list)
{
	arg_list->file2 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (arg_list->file2 == -1)
	{
		error_msg(filename, arg_list, 1);
	}
}

int	check_args_num(int argc)
{
	if (argc != 5)
	{
		return (1);
	}
	return (0);
}
