/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:49:30 by mipham            #+#    #+#             */
/*   Updated: 2017/11/10 20:08:28 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *tmp;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	result = ft_lstnew(tmp->content, tmp->content_size);
	if (result)
	{
		new = result;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			new = new->next;
			lst = lst->next;
		}
	}
	return (result);
}
