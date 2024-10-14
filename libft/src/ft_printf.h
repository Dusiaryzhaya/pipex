/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:32:32 by anilchen          #+#    #+#             */
/*   Updated: 2024/08/28 14:26:14 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_printstring(char *s, int *count, int fd);
int		ft_printchar(char c, int *count, int fd);
int		ft_printnum(int num, int *count, int fd);
void	ft_printf_reverse(int size, char *arr);
void	ft_convert_to_unsigned(int n, int *count, int fd);
void	ft_pointer_to_hex(void *ptr, int *count, int fd);
void	ft_int_to_hex(char format, unsigned int num, int *count, int fd);

#endif