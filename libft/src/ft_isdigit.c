/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:06:26 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/14 13:46:16 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c = 'j';
// 	int res = ft_isdigit(c);
// 	printf("%d\n", res);
// 	return (0);
// }