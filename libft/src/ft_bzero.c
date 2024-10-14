/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:16:01 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/19 12:36:09 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция bzero устанавливает все байты области памяти в ноль,
// в отличие от memset,kоторая устанавливает все байты в указанное значение.
// Аргументы:
// str: указатель на область памяти, которую нужно обнулить.
// count: количество байтов для обнуления.

void	ft_bzero(void *str, size_t count)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)str;
	while (i < count)
	{
		arr[i] = 0;
		i++;
	}
}

// #include <stdio.h>

// int main()
// {
// 	char c = 'c';
//     char str[20] = "Hello, World!";
//     printf("Original string: %s\n", str);
//     ft_bzero(str, 5);
//     printf("Modified string: %s\n", str);
//     return (0);
// }