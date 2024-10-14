/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:56:08 by anilchen          #+#    #+#             */
/*   Updated: 2024/08/28 14:26:39 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_is_null(int fd, int *count)
{
	write(fd, "(nil)", 5);
	*count += 5;
}

void	ft_pointer_to_hex(void *ptr, int *count, int fd)
{
	unsigned long long	adress;
	size_t				i;
	char				buffer[19];

	i = 0;
	if (!ptr)
	{
		pointer_is_null(fd, count);
		return ;
	}
	adress = (unsigned long long)ptr;
	while (adress > 0)
	{
		buffer[i++] = "0123456789abcdef"[adress % 16];
		adress /= 16;
	}
	buffer[i++] = 'x';
	buffer[i++] = '0';
	ft_printf_reverse(i, buffer);
	buffer[i] = '\0';
	ft_printstring(buffer, count, fd);
}
