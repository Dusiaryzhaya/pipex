/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:45:46 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/14 14:32:48 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPEX_H
#ifdef PIPEX_H

# include "../libft/src/ft_printf.h"
# include "../libft/src/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_args
{
	int		file1;
	int		file2;
	char	**cmd1_args;
	char	**cmd2_args;
}			t_args;

void		free_args(t_args *arg_list);
void		error_msg(const char *str, t_args *arg_list, int error_type);
void		check_file_readable(const char *filename, t_args *arg_list);
void		check_file_writable(const char *filename, t_args *arg_list);
int			check_args_num(int argc);
char		*find_full_path(const char *cmd, t_args *arg_list, char *envp[]);
void		free_all_paths(char **all_paths);

#endif