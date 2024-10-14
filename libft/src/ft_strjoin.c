/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:24:42 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/20 17:55:12 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*strjoin;

	len_s1 = 0;
	len_s2 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	strjoin = (char *)malloc(len_s1 + len_s2 + 1);
	if (!strjoin)
		return (NULL);
	if (s1)
		ft_memcpy(strjoin, s1, len_s1);
	if (s2)
		ft_memcpy(strjoin + len_s1, s2, len_s2);
	strjoin[len_s1 + len_s2] = '\0';
	return (strjoin);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char const *s1 = "Hello, ";
// 	char const *s2 = "world";
// 	char *res = ft_strjoin(s1, s2);
// 	printf("%s", res);
// 	return (0);
// }