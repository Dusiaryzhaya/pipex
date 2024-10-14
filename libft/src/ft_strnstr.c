/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:01:58 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/25 16:52:54 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция strnstr в языке программирования C используется для поиска подстроки
// в строке, но с ограничением на количество символов для поиска. Она ищет
// первое вхождение подстроки (needle) в строке (haystack), но рассматривает
// только первые n символов haystack.
// Аргументы:
// haystack: указатель на строку, в которой производится поиск.
// needle: указатель на строку, которую нужно найти.
// len: максимальное количество символов для поиска в строке haystack.
// Возвращаемое значение:
// Указатель на первое вхождение подстроки needle в строке haystack
// в пределах первых len символов, если подстрока найдена.
// NULL, если подстрока не найдена.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	needle_len = ft_strlen(needle);
	while (*haystack && needle_len <= len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle,
				needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}

// int	main(void)
// {
// 	const char *haystack = "abcdefgh";
// 	const char *needle = "";
// 	size_t len = 0;

// 	char *result = ft_strnstr(haystack, needle, len);

// 	if (result != NULL)
// 	{
// 		printf("Подстрока найдена: %s\n", result);
// 	}
// 	else
// 	{
// 		printf("Подстрока не найдена.\n");
// 	}

// 	return (0);
// }