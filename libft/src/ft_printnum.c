/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:53:04 by anilchen          #+#    #+#             */
/*   Updated: 2024/07/04 14:00:10 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnum(int num, int *count, int fd)
{
	ft_putnbr_fd(num, fd);
	if (num == 0)
	{
		*count += 1;
	}
	if (num < 0)
	{
		num = -num;
		(*count)++;
	}
	while (num != 0)
	{
		num /= 10;
		(*count)++;
	}
	return (*count);
}
