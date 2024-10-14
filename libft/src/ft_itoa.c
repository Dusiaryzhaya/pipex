/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:54:19 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/25 16:51:22 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.
// Return value
// The string representing the integer.
// NULL if the allocation fails.

int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_reverse(char *arr, int length)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = length - 1;
	while (i < j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

void	*ft_intmin(void)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(12 * sizeof(char));
	if (!arr)
		return (NULL);
	arr[i++] = '-';
	arr[i++] = '2';
	arr[i++] = '1';
	arr[i++] = '4';
	arr[i++] = '7';
	arr[i++] = '4';
	arr[i++] = '8';
	arr[i++] = '3';
	arr[i++] = '6';
	arr[i++] = '4';
	arr[i++] = '8';
	arr[i] = '\0';
	return (arr);
}

void	ft_div(char *arr, int n, int *i)
{
	while (n != 0)
	{
		arr[(*i)++] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		i;
	int		is_negative;

	i = 0;
	is_negative = 0;
	if (n == -2147483648)
		return (ft_intmin());
	arr = (char *)malloc((ft_count_digits(n) + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	if (n == 0)
		arr[i++] = '0';
	else
		ft_div(arr, n, &i);
	if (is_negative == 1)
		arr[i++] = '-';
	arr[i] = '\0';
	ft_reverse(arr, i);
	return (arr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int n = -2147483648;
// 	char *res = ft_itoa(n);
// 	printf("%s\n", res);
// 	return (0);
// }