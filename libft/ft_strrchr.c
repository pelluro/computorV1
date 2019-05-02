/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:38:27 by mipham            #+#    #+#             */
/*   Updated: 2017/11/09 16:10:25 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	int		size;

	src = (char *)s;
	size = ft_strlen(src);
	while (size != 0 && src[size] != (char)c)
		size--;
	if (src[size] == (char)c)
		return (src + size);
	return (0);
}
