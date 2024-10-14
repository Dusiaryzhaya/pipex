/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:27:49 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/21 16:15:20 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция strrchr в языке программирования C используется для поиска
// последнего вхождения указанного символа в строке. Она ищет символ
// в строке и возвращает указатель на последнее его вхождение.

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_pos;

	last_pos = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			last_pos = str;
		}
		str++;
	}
	if ((char)c == '\0' && *str == (char)c)
	{
		return ((char *)str);
	}
	return ((char *)last_pos);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str = "Hello!0";
// 	const char	*res = ft_strrchr(str, '!');

// 	printf("%s\n", res);
// 	return (0);
// }
