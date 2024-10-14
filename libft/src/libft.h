/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:55:04 by anilchen          #+#    #+#             */
/*   Updated: 2024/08/19 17:17:58 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ************************************************************************** */
/*                                  CHECKING                                  */
/* ************************************************************************** */

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);

/* ************************************************************************** */
/*                                 MEMORY                                     */
/* ************************************************************************** */

void				ft_bzero(void *str, size_t count);
void				*ft_calloc(size_t num, size_t size);
void				*ft_memchr(void const *str, int c, size_t num);
int					ft_memcmp(const void *str1, const void *str2, size_t num);
void				*ft_memcpy(void *dest, void const *src, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memset(void *str, int c, size_t num);

/* ************************************************************************** */
/*                                  PRINT                                     */
/* ************************************************************************** */

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*get_next_line(int fd);

/* ************************************************************************** */
/*                                 STRING                                     */
/* ************************************************************************** */

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strchr(char const *str, int c);
char				*ft_strdup(const char *str);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, char const *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *str1, const char *str2, size_t num);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

/* ************************************************************************** */
/*                                   LIST                                     */
/* ************************************************************************** */

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

#endif