/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:14:03 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/24 16:47:15 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Копирует count байты (memmove) из src to dest. Если некоторые части исходного
// и целевого регионов перекрываются, функции гарантируют,
//	что исходные байты в перекрывающейся области копируются перед перезаписью.

static void	ft_copy_forward(char *dst, const char *src, size_t num)
{
	while (num--)
	{
		*dst++ = *src++;
	}
}

static void	ft_copy_backward(char *dst, const char *src, size_t num)
{
	dst += num;
	src += num;
	while (num--)
	{
		*--dst = *--src;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char		*dst;
	const char	*sc;
	char		*dst_end;
	const char	*sc_end;

	if (!dest && !src)
	{
		return (NULL);
	}
	dst = (char *)dest;
	sc = (const char *)src;
	dst_end = dst + num;
	sc_end = sc + num;
	if (dst < sc && dst_end > sc)
		ft_copy_forward(dst, sc, num);
	else if (dst > sc && dst < sc_end)
		ft_copy_backward(dst, sc, num);
	else
		ft_copy_forward(dst, sc, num);
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char src[20] = "Hello, Hypex!";
// 	char dest[20] = "fuckn  World! hjkl;;";
// 	ft_memmove(&dest[0], &src[7], 5);
// 	printf("Modified string: %s\n", dest);
// 	return (0);
// }