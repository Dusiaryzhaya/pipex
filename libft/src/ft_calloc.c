/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:36:36 by anilchen          #+#    #+#             */
/*   Updated: 2024/10/08 11:27:55 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция calloc в языке программирования C используется для выделения
// и инициализации памяти для массива. В отличие от malloc, которая
// просто выделяет память, calloc выделяет память и заполняет её нулями.
// Возвращаемое значение:
// Указатель на выделенную и инициализированную память.
// Если выделение памяти не удалось, возвращает NULL.
// Особенности:
// calloc гарантирует, что вся выделенная память будет инициализирована нулями.
// При выделении памяти с использованием calloc, общий выделяемый
// размер памяти будет равен num * size байтов.
// Аргументы:
// num: количество элементов.
// size: размер каждого элемента в байтах.

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	arr_size;
	char	*arr;

	if (!num || !size)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	arr_size = num * size;
	ptr = malloc(arr_size);
	if (ptr == NULL)
		return (NULL);
	else
	{
		arr = (char *)ptr;
		ft_bzero(arr, arr_size);
	}
	return (ptr);
}

// int	main(void)
// {
// 	size_t	num;
// 	size_t	size;
// 	int		*arr;

// 	num = 5;
// 	size = sizeof(int);
// 	arr = (int *)ft_calloc(num, size);
// 	if (arr != NULL)
// 	{
// 		for (size_t i = 0; i < num; i++)
// 		{
// 			printf("%d", arr[i]);
// 		}
// 		free(arr); // Don't forget to free the allocated memory
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}
// 	return (0);
// }
