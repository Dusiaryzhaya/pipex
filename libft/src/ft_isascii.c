/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:08:03 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/14 13:46:16 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c = 'l';
// 	int res = ft_isascii(c);
// 	printf("%d\n", res);
// 	return (0);
// }