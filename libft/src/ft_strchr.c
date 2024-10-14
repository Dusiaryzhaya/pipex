/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:19:43 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/25 16:52:54 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция strchr в языке программирования C используется для поиска
// первого вхождения указанного символа в строке.
// Возвращаемое значение:
// Указатель на первое вхождение символа c в строку str, если символ найден.
// NULL, если символ c не найден в строке str.

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((char)c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char *str = "teste";
// 	const char *res = ft_strchr(str, '\0');
// 	printf("%s\n", res);
// 	return (0);
// }