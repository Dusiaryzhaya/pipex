/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:39:31 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/26 16:10:57 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*ihatenames;

	new_list = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		ihatenames = f(lst->content);
		new_elem = ft_lstnew(ihatenames);
		if (new_elem == NULL)
		{
			del(ihatenames);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (new_list == NULL)
			new_list = new_elem;
		else
			ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
