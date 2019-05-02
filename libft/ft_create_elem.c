/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:17:10 by mipham            #+#    #+#             */
/*   Updated: 2017/11/13 14:18:43 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(list));
	if (!list)
		return (list);
	list->content = data;
	list->next = NULL;
	return (list);
}
