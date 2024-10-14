/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:37 by anilchen          #+#    #+#             */
/*   Updated: 2024/08/28 14:26:46 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_to_unsigned(int n, int *count, int fd)
{
	unsigned int	num;
	char			buffer[32];
	int				i;

	num = (unsigned int)n;
	i = 0;
	if (num == 0)
	{
		ft_printchar('0', count, fd);
		return ;
	}
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	ft_printf_reverse(i, buffer);
	buffer[i] = '\0';
	ft_printstring(buffer, count, fd);
}
