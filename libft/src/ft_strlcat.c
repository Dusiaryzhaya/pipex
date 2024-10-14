/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:20:33 by anilchen          #+#    #+#             */
/*   Updated: 2024/07/19 17:13:45 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

// Функция strlcat является аналогом strcat, но с добавлением дополнительной
// проверки для предотвращения переполнения буфера. Она используется для
// конкатенации двух строк с учетом максимального размера буфера-приемника.

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	while (src[i - dest_len] != '\0' && i < size - 1)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char src[] = "world!";
// 	char dest[100] = "Hello, ";

// 	ft_strlcat(dest, src, sizeof(dest));
// 	printf("Содержимое dest: %s\n", dest);
// 	return (0);
// }