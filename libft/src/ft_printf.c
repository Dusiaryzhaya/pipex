/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:37:02 by anilchen          #+#    #+#             */
/*   Updated: 2024/08/28 14:27:08 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format, int fd, int *count)
{
	int	num;

	if (format == 's')
		ft_printstring(va_arg(args, char *), count, fd);
	else if (format == 'c')
		ft_printchar((char)va_arg(args, int), count, fd);
	else if (format == 'd' || format == 'i')
		ft_printnum(va_arg(args, int), count, fd);
	else if (format == 'p')
		ft_pointer_to_hex(va_arg(args, void *), count, fd);
	else if (format == 'u')
	{
		num = va_arg(args, int);
		if (num < 0)
			ft_convert_to_unsigned(num, count, fd);
		else
			ft_printnum(num, count, fd);
	}
	else if (format == 'x' || format == 'X')
		ft_int_to_hex(format, va_arg(args, int), count, fd);
	else if (format == '%')
	{
		ft_printchar('%', count, fd);
	}
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	int		fd;
	int		count;
	int		i;
	va_list	args;

	fd = 1;
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_formats(args, format[i + 1], fd, &count);
			i++;
		}
		else
		{
			write(fd, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char	*str;
// 	int		count;
// 	int		mycount;
// 	char	c;
// 	int		num;
// 	void	*p;
// 	void	*ptr;

// 	num = 1709;
// 	str = "Anna";
// 	// String
// 	printf("Printing string. Expected:\n");
// 	count = printf("%s\n", str);
// 	printf("%d\n", count);
// 	printf("Printing string. Result:\n");
// 	mycount = ft_printf("%s\n", str);
// 	printf("%d\n", mycount);
// 	// Char
// 	c = 'c';
// 	printf("Printing char. Expected:\n");
// 	count = printf("%c\n", c);
// 	printf("%d\n", count);
// 	printf("Printing char. Result:\n");
// 	mycount = ft_printf("%c\n", c);
// 	printf("%d\n", mycount);
// 	//Num
// 	num = -1709;
// 	printf("Printing num. Expected:\n");
// 	count = printf("%u\n", num);
// 	printf("%d\n", count);
// 	printf("Printing num. Result:\n");
// 	mycount = ft_printf("%u\n", num);
// 	printf("%d\n", mycount);
// 		// %
// 		printf("Printing num. Expected:\n");
// 		count = printf("%%\n");
// 		printf("%d\n", count);
// 		printf("Printing num. Result:\n");
// 		mycount = ft_printf("%%\n");
// 		printf("%d\n", mycount);
// 		// Pointer adress
// 		printf("Printing The void * pointer argument has \
// to be printed in hexadecimal format. Expected:\n");
// 		count = printf("%p\n", p);
// 		printf("%d\n", count);
// 		printf("Printing The void * pointer argument has \
// to be printed in hexadecimal format. Result:\n");
// 		mycount = ft_printf("%p\n", p);
// 		printf("%d\n", mycount);
// 	// unsigned int
// 	printf("Printing an unsigned decimal (base 10) number. Expected:\n");
// 	count = printf("%u\n", num);
// 	printf("%d\n", count);
// 	printf("Printing an unsigned decimal (base 10) number. Result:\n");
// 	mycount = ft_printf("%u\n", num);
// 	printf("%d\n", mycount);
// 	// hexadecimal (base 16) lowercase format
// 	printf("Printing a number in hexadecimal \
// (base 16) lowercase format. Expected:\n");
// 	count = printf("%x\n", num);
// 	printf("%d\n", count);
// 	printf("Printing a number in hexadecimal (base 16) \
//  lowercase format. Result:\n");
// 	mycount = ft_printf("%x\n", num);
// 	printf("%d\n", mycount);
// 	// hexadecimal (base 16) uppercase format
// 	printf("Printing a number in hexadecimal (base 16) \
//  uppercase format. Expected:\n");
// 	count = printf("%X\n", num);
// 	printf("%d\n", count);
// 	printf("Printing a number in hexadecimal (base 16) \
//  uppercase format. Result:\n");
// 	mycount = ft_printf("%X\n", num);
// 	printf("%d\n", mycount);
// 	c = 'c';
// 	int num2 = -1709;
// 	printf("Testing more then one format. Expected:\n");
// 	count = printf("My name is %s, my birthday is %d. My char is %c, \
// 			My pointer adress is %p. Look how I can: %u, %x, %i, %X\n", str,
// 				num, c, \
// 				ptr, num, num, num2, num2);
// 	printf("%d\n", count);
// 	printf("Testing more then one format. Result:\n");
// 	mycount = ft_printf("My name is %s, my birthday is %d. My char is %c, \
// 			My pointer adress is %p. Look how I can: %u, %x, %i, %X\n", str,
// 				num, c, \
// 				ptr, num, num, num2, num2);
// 	printf("%d\n", mycount);
// 	return (0);
// }
