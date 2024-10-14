/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:02:09 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/25 16:52:54 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the string ’s’ to the given file
// descriptor.

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

// int	main(void)
// {
// 	char	*s;
// 	int		fd;

// 	s = "cat";
// 	fd = 1;
// 	ft_putstr_fd(s, fd);
// 	return (0);
// }
