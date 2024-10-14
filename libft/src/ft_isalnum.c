/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:07:13 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/14 13:46:16 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns 1 if argument is an alphanumeric character.
// Returns 0 if argument is neither an alphabet nor a digit.

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A'
			&& c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c = 'j';
// 	int res = ft_isalnum(c);
// 	printf("%d\n", res);
// 	return (0);
// }