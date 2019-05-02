/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:04:44 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 17:47:18 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *restrict str1, const void *restrict str2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = str1;
	src = str2;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (str1);
}
