/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:49:34 by mipham            #+#    #+#             */
/*   Updated: 2017/11/09 15:38:11 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	int		i;

	src = (char *)s;
	i = 0;
	while (src[i] && src[i] != (char)c)
		i++;
	if (src[i] == (char)c)
		return (src + i);
	return (0);
}
