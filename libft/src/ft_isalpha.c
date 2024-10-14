/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:19:43 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/19 12:46:17 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zero (0)	If the parameter isn't an alphabet.
// Non zero number	If the parameter is an alphabet.

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c = '5';
// 	int res = ft_isalpha(c);
// 	printf("%d\n", res);
// 	return (0);
// }
