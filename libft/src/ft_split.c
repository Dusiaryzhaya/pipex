/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:05:28 by anilchen          #+#    #+#             */
/*   Updated: 2024/08/19 17:30:41 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_substrings(char const *s, char c)
{
	int	count;
	int	is_it_delimiter;

	count = 0;
	is_it_delimiter = 0;
	while (*s)
	{
		if (*s != c && is_it_delimiter == 0)
		{
			is_it_delimiter = 1;
			count++;
		}
		else if (*s == c)
		{
			is_it_delimiter = 0;
		}
		s++;
	}
	return (count);
}

void	ft_free_split(char **split, int i)
{
	while (i > 0)
	{
		free(split[--i]);
	}
	free(split);
}

char	**ft_split2(char const *s, char c, char **arr, size_t substr_count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (i < substr_count)
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		arr[i] = ft_substr(s, start, j - start);
		if (arr[i] == NULL)
		{
			ft_free_split(arr, i);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	substr_count;

	if (!s)
		return (NULL);
	substr_count = count_substrings(s, c);
	arr = (char **)malloc(sizeof(char *) * (substr_count + 1));
	if (!arr)
		return (NULL);
	arr = ft_split2(s, c, arr, substr_count);
	return (arr);
}

// int main(void)
// {
//     char const *s;
//     char **res;

//     s = "asdl123lkjhloil456l ";
//     res = ft_split(s, 'l');
//     if (res == NULL)
//     {
//         printf("Ошибка выделения памяти.\n");
//         return (1);
//     }
//     for (int i = 0; res[i] != NULL; i++)
//     {
//         printf("%s\n", res[i]); // Выводим каждую подстроку
//         free(res[i]); // Освобождаем каждую подстроку
//     }
//     free(res); // Освобождаем массив указателей
//     return (0);
// }
