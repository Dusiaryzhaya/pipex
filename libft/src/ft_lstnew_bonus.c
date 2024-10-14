/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:19:22 by anilchen          #+#    #+#             */
/*   Updated: 2024/07/10 13:26:18 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
	{
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

#include <stdio.h>

int	main(void)
{
	int value = 42;
	t_list *node = ft_lstnew(&value); // Создание узла с указателем на int

	// Пример вывода значения content узла
	printf("Value stored in node: %d\n", *(int *)(node->content));

	free(node); // Освобождение памяти
	return (0);
}