/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:17:33 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 16:29:03 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char			**res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	i = 0;
	j = 0;
	if (!s || !c ||
			!(res = (char **)malloc(sizeof(char*) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			size = 0;
			while (s[i + size] && (s[i + size] != c))
				size++;
			res[j++] = ft_strsub(s, i, size);
			i = i + size;
		}
	}
	res[j] = 0;
	return (res);
}
