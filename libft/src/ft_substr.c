/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:01:26 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/25 16:52:54 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.
// s: The string from which to create the substring.
// start: The start index of the substring in the
// string ’s’.
// len: The maximum length of the substring

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*sbstr;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (len > str_len - start)
		len = str_len - start;
	if (start >= str_len)
		return (ft_strdup(""));
	sbstr = malloc(len + 1 * sizeof(char));
	if (!sbstr)
		return (NULL);
	ft_strlcpy(sbstr, s + start, len + 1);
	return (sbstr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "";
// 	char *res = ft_substr(s, 1, 1);
// 	printf("%s", res);
// 	return (0);
// }