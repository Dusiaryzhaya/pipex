/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:51:19 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/25 16:51:25 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the character ’c’ to the given file
// descriptor.

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

// int	main(void)
// {
// 	char	c;
// 	int		fd;

// 	c = 'c';
// 	fd = 1;
// 	ft_putchar_fd(c, fd);
// 	return (0);
// }
