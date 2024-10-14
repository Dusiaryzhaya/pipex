/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:07:21 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/18 16:36:04 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.
// s1: The string to be trimmed.
// set: The reference set of characters to trim.

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		len;
	int		start;
	int		end;
	char	*strtrim;
	int		i;

	len = ft_strlen(s1);
	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = len - 1;
	while (end > start && is_in_set(s1[end], set))
		end--;
	strtrim = (char *)malloc(end - start + 2);
	if (strtrim == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		strtrim[i++] = s1[start++];
	strtrim[i] = '\0';
	return (strtrim);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s1 = "lHello!lllll";
// 	const char	*set = "l";
// 	char		*res;

// 	res = ft_strtrim(s1, set);
// 	if (res == NULL)
// 	{
// 		printf("Memory allocation failed.\n");
// 		return (1);
// 	}
// 	printf("Original: '%s'\n", s1);
// 	printf("Trimmed: '%s'\n", res);
// 	free(res);
// 	return (0);
// }