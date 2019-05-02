/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:36:21 by mipham            #+#    #+#             */
/*   Updated: 2017/11/13 13:42:19 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	char		*dest;
	const char	*src;

	dest = d;
	src = s;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		src = src + n - 1;
		dest = dest + n - 1;
		while (n > 0)
		{
			*dest-- = *src--;
			n--;
		}
	}
	else
	{
		while (n--)
			*dest++ = *src++;
	}
	return (d);
}
