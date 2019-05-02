/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:47:24 by mipham            #+#    #+#             */
/*   Updated: 2017/11/10 17:51:09 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char*)ft_memchr(dst, '\0', len);
	if (!s1)
		return (len + ft_strlen((char*)src));
	s2 = (char*)src;
	i = ft_strlen((char*)dst) + ft_strlen((char*)src);
	while ((size_t)(s1 - dst) < len - 1 && *s2)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (i);
}
