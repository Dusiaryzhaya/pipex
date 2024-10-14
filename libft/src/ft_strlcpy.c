/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:10:17 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/24 16:49:11 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция strlcpy используется для безопасного копирования строк.
// В отличие от стандартной функции strcpy, strlcpy предотвращает
// переполнение буфера путем копирования не более size - 1 символов
// из строки-источника в строку-приемник и гарантирует, что строка-приемник
// всегда завершается нулевым символом.

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char			src[] = "Hello, world! Or no I dont know because";
// 	char			dest[20];
// 	unsigned int	copied;

// 	copied = ft_strlcpy(dest, src, sizeof(dest));
// 	printf("Содержимое dest: %s\n", dest);
// 	return (0);
// }
