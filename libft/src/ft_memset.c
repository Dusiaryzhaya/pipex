/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:12:48 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/19 18:09:58 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция memset в языке программирования C используется для установки
// определённого значения(байта) во все байты указанного блока памяти.
// Эта функция может быть полезна для инициализации массива или для установки
// всех элементов массива в одно и то же значение.

void	*ft_memset(void *str, int c, size_t num)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < num)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c = 'c';
// 	char str[20] = "Hello, World!";
// 	printf("Original string: %s\n", str);

// 	ft_memset(str, c, 5);
// 	printf("Modified string: %s\n", str);

// 	return (0);
// }