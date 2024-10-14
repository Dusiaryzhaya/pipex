/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:13:33 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/24 16:44:01 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция memcpy в языке программирования C используется для копирования
// блока памяти из одного места в другое. Она копирует n байтов из области
// памяти, на которую указывает аргумент src, в область памяти, на которую
// указывает аргумент dest.

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sc;

	i = 0;
	if (!dest && !src)
	{
		return (NULL);
	}
	if (num == 0)
	{
		return (dest);
	}
	dst = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	while (i < num)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char src[20] = "Hello, Hypex!";
// 	char dest[20] = "fuckn  World!";

// 	ft_memcpy(dest, src, 6);
// 	printf("Modified string: %s\n", dest);

// 	return (0);
// }