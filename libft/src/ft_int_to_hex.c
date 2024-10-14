/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:57:52 by anilchen          #+#    #+#             */
/*   Updated: 2024/08/28 14:26:55 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convertion(unsigned int num, char *arr, int *i)
{
	int	digit;

	while (num != 0)
	{
		digit = num % 16;
		if (digit < 10)
			arr[(*i)++] = digit + '0';
		else
			arr[(*i)++] = 'a' + (digit - 10);
		num /= 16;
	}
}

void	ft_uppercase(char *arr, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		arr[j] = ft_toupper(arr[j]);
		j++;
	}
}

void	ft_int_to_hex(char format, unsigned int num, int *count, int fd)
{
	char	arr[17];
	int		i;

	i = 0;
	if (num == 0)
	{
		ft_printchar('0', count, fd);
		return ;
	}
	ft_convertion(num, arr, &i);
	ft_printf_reverse(i, arr);
	arr[i] = '\0';
	if (format == 'X')
	{
		ft_uppercase(arr, i);
	}
	ft_printstring(arr, count, fd);
}
