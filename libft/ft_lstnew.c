/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:50:02 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 15:59:14 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_elem;

	new_elem = NULL;
	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_elem->next = NULL;
	if (content == NULL)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	else
	{
		new_elem->content = malloc(sizeof(content_size));
		if (new_elem->content == NULL)
			return (NULL);
		ft_memcpy(new_elem->content, content, content_size);
		new_elem->content_size = content_size;
	}
	new_elem->next = NULL;
	return (new_elem);
}
