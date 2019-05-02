/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:50:07 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:27 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_tabnew(size_t size)
{
	int	*str;

	if (!(str = (int*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
