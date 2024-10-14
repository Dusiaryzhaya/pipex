/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:35:38 by anilchen          #+#    #+#             */
/*   Updated: 2024/07/04 13:23:00 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(char *s, int *count, int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		*count += 6;
		return (*count);
	}
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
		(*count)++;
	}
	return (*count);
}
