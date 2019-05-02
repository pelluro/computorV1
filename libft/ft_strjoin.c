/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:35:31 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 16:06:51 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		size = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (*s1)
			res[i++] = *s1++;
		while (*s2)
			res[i++] = *s2++;
		res[i] = '\0';
		return (res);
	}
	return (0);
}
