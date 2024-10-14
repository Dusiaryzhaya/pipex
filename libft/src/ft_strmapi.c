/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:35:16 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/25 16:52:54 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Return value
// The string created from the successive applications
// of ’f’.
// Returns NULL if the allocation fails.
// Applies the function f to each character of the
// string s, passing its index as the first argument
// and the character itself as the second. A new
// string is created (using malloc) to collect the
// results from the successive applications of f

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	arr = (char *)malloc((ft_strlen(s) + 1) * (sizeof(char)));
	if (arr == NULL)
	{
		return (NULL);
	}
	while (s[i])
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

// int main()
// {
//     char *s = "example";
//     char *result = ft_strmapi(s, ft_function);
//     printf("Result: %s\n", result);
//     free(result);
//     return (0);
// }